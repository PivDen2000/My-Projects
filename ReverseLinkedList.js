class Node{
    constructor(value, nextNode){
        this.value = value;
        this.nextNode = nextNode;
    }
}

let print = (node)=>{
    console.log("Start");
    while (node){
        console.log(node.value);
        node = node.nextNode;
    }
    console.log("Finish");
};

let reverse = (node)=>{
    if(!node || !node.nextNode) return node;
    
    let temp = node;
    if(!node.nextNode.nextNode) {
        temp = node.nextNode;
        node.nextNode.nextNode = node;
        node.nextNode = null;
        return temp;
    }
    
    let tempNext = temp.nextNode;
    let tempNextNext = tempNext.nextNode;
    while(tempNextNext){
        tempNext.nextNode = temp;
        
        temp = tempNext;
        tempNext = tempNextNext;
        tempNextNext = tempNextNext.nextNode;
    }
    tempNext.nextNode = temp;
    node.nextNode = null;
    
    return tempNext;
};

let node5 = new Node(5, null);
let node4 = new Node(4, node5);
let node3 = new Node(3, node4);
let node2 = new Node(2, node3);
let node1 = new Node(1, node2);

print(node1);
reverse(node1);
console.log("REVERSED");
print(node5);