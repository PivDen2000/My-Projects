using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace ImageGroupByIsFlash
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input path folder with photos:");
            var root = Console.ReadLine();

            while (!Directory.Exists(root))
            {
                Console.WriteLine("Directory at this path does not exist, enter correct path, please.");
                root = Console.ReadLine();
            }

            Console.WriteLine("Started");

            var folders = new List<string>();
            GetFolders(folders, root);

            var flashedDir = CreateFolder($"{root}-flashed");
            CopyFolders(folders, root, flashedDir);
            var unflashedDir = CreateFolder($"{root}-unflashed");
            CopyFolders(folders, root, unflashedDir);

            var files = new List<string>();
            foreach (var folder in folders)
                files.AddRange(Directory.GetFiles(folder));

            var photos = new List<string>();
            foreach (var file in files)
            {
                if (file.EndsWith(".JPG"))
                    photos.Add(file);
            }    

            var tasks = new List<Task>();
            foreach (var photoPath in photos)
                tasks.Add(ImageFilter(photoPath, flashedDir, unflashedDir, root));

            Task.WaitAll(tasks.ToArray());
            Console.WriteLine("Finished");
            Console.ReadKey();
        }

        static void GetFolders(List<string> folders, string directory)
        {
            var DI = new DirectoryInfo(directory);
            var SubDir = DI.GetDirectories();
            foreach (var dir in SubDir)
                GetFolders(folders, dir.FullName);
            folders.Add(directory);
        }
        static string CreateFolder(string folder)
        {
            if (Directory.Exists(folder))
                Directory.Delete(folder, true);
            Directory.CreateDirectory(folder);
            return folder;
        }

        static void CopyFolders(List<string> folders, string from, string to) {
            foreach (var folder in folders)
                Directory.CreateDirectory(to + folder.Substring(from.Length));
        }

        static async Task ImageFilter(string imagePath, string flashedDir, string unflashedDir, string root)
        {
            await Task.Run(() =>
            {
                var image = new Bitmap(imagePath);
                var value = BitConverter.ToString(image.PropertyItems.FirstOrDefault(x => x.Id.ToString("x") == "9209").Value);
                var list = new List<string>() { "00-00", "10-00", "18-00", "20-00" };
                var targetPath = (list.Contains(value) ? unflashedDir : flashedDir) + imagePath.Substring(root.Length);
                File.Copy(imagePath, targetPath);
            });
        }
    }
}