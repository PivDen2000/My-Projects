let rand = (n, m, p = 0.5) => {
    let res = [];
    let temp = 0;
    for(let i = 0; i < n; ++i){
        res.push([]);
        for(let j = 0; j < m; ++j){
            res[i].push((Math.random() < p) ? 1 : 0);
        }
    }
    return res;
}

let print = (matrix) => {
    for(let i = 0; i < matrix.length; ++i){
        console.log(matrix[i]);
    }
}

let alg = (matrix) => {
    let index;
    let n = matrix.length;
    let m = matrix[0].length;
    let max = 0;
    let dim = 0;
    let row,col;
    for(let i = 0; i < n; ++i){
        for(let j = 0; j < m; ++j){
            if(matrix[i][j] == 1){
                dim = 0;
                row = 0;
                col = 0;
                for(let k=0; k < Math.pow(Math.min(n-i,m-j),2); ++k){
                    if(matrix[i+row][j+col] == 0) break;
                    if(col==0){
                        col = row+1;
                        row = 0;
                        dim++;
                    } else if(row < col){
                        row++;
                    } else {
                        col--;
                    }
                }
                if(max < dim){
                    max = dim;
                    index = '('+(i+1)+','+(j+1)+')'; 
                }
            }
        }
    }
    return max + ' ' + index;
}

let mat = rand(20,20,0.9);
print(mat);
console.log(alg(mat));