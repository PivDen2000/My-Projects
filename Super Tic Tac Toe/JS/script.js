const big = [
    '', '', '',
    '', '', '',
    '', '', ''
];
const small = [
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ],
    [
        '', '', '',
        '', '', '',
        '', '', ''
    ]
];
const convertorMap = {
    [00]: [1, 1],
    [01]: [1, 2],
    [02]: [1, 3],
    [03]: [2, 1],
    [04]: [2, 2],
    [05]: [2, 3],
    [06]: [3, 1],
    [07]: [3, 2],
    [08]: [3, 3],
    [10]: [1, 4],
    [11]: [1, 5],
    [12]: [1, 6],
    [13]: [2, 4],
    [14]: [2, 5],
    [15]: [2, 6],
    [16]: [3, 4],
    [17]: [3, 5],
    [18]: [3, 6],
    [20]: [1, 7],
    [21]: [1, 8],
    [22]: [1, 9],
    [23]: [2, 7],
    [24]: [2, 8],
    [25]: [2, 9],
    [26]: [3, 7],
    [27]: [3, 8],
    [28]: [3, 9],
    [31]: [4, 2],
    [32]: [4, 3],
    [30]: [4, 1],
    [33]: [5, 1],
    [34]: [5, 2],
    [35]: [5, 3],
    [36]: [6, 1],
    [37]: [6, 2],
    [38]: [6, 3],
    [40]: [4, 4],
    [41]: [4, 5],
    [42]: [4, 6],
    [43]: [5, 4],
    [44]: [5, 5],
    [45]: [5, 6],
    [46]: [6, 4],
    [47]: [6, 5],
    [48]: [6, 6],
    [50]: [4, 7],
    [51]: [4, 8],
    [52]: [4, 9],
    [53]: [5, 7],
    [54]: [5, 8],
    [55]: [5, 9],
    [56]: [6, 7],
    [57]: [6, 8],
    [58]: [6, 9],
    [60]: [7, 1],
    [61]: [7, 2],
    [62]: [7, 3],
    [63]: [8, 1],
    [64]: [8, 2],
    [65]: [8, 3],
    [66]: [9, 1],
    [67]: [9, 2],
    [68]: [9, 3],
    [70]: [7, 4],
    [71]: [7, 5],
    [72]: [7, 6],
    [73]: [8, 4],
    [74]: [8, 5],
    [75]: [8, 6],
    [76]: [9, 4],
    [77]: [9, 5],
    [78]: [9, 6],
    [80]: [7, 7],
    [81]: [7, 8],
    [82]: [7, 9],
    [83]: [8, 7],
    [84]: [8, 8],
    [85]: [8, 9],
    [86]: [9, 7],
    [87]: [9, 8],
    [88]: [9, 9]
};
let player = 'X' /*XO*/
let availableBig = -1;
let winner = false;
const winningCells = [false, false, false, false, false, false, false, false, false];

const convertor = (i, j) => {
    return convertorMap[parseInt(10 * i, 10) + parseInt(j, 10)];
};
const checkHelp = (a, b, c, i = 0) => {
    if (big[a] !== '' && big[a] === big[b] && big[b] === big[c]) {
        winningCells[a] = true;
        winningCells[b] = true;
        winningCells[c] = true;
    }
    return (small[i][a] !== '' && small[i][a] === small[i][b] && small[i][b] === small[i][c]);
}
const checkSmallWinner = (i) => {
    return (checkHelp(0, 1, 2, i) ||
        checkHelp(3, 4, 5, i) ||
        checkHelp(6, 7, 8, i) ||
        checkHelp(0, 3, 6, i) ||
        checkHelp(1, 4, 7, i) ||
        checkHelp(2, 5, 8, i) ||
        checkHelp(0, 4, 8, i) ||
        checkHelp(2, 4, 6, i))
}
const checkBigWinner = () => {
    checkHelp(0, 4, 8);
    checkHelp(2, 4, 6);
    for (let k = 0; k < 3; k++) {
        checkHelp(3 * k, 3 * k + 1, 3 * k + 2);
        checkHelp(k, k + 3, k + 6);
    }
    return winningCells.find(element => element);
}
const classToggle = (elementClass, optionClass, option) => {
    (option === "add") ?
    document.querySelectorAll('.' + elementClass).forEach(element => element.classList.add(optionClass)):
        document.querySelectorAll('.' + elementClass).forEach(element => element.classList.remove(optionClass));
}
const action = (target, symbol) => {
    target.style = symbol === 'X' ? "color: Red" : "color: Blue";
    target.classList.add("lastTurn");
    target.innerHTML = symbol;
}

const area = document.querySelector('#area');
for (let i = 0; i < 9; i++) {
    const bigCell = document.createElement('div');
    bigCell.classList.add("cell", "bigCell", "available");
    bigCell.id = i;
    area.appendChild(bigCell);
    if (!big[i]) {
        for (let j = 0; j < 9; j++) {
            const smallCell = document.createElement('div');
            smallCell.classList.add("cell", "smallCell");
            smallCell.id = j;
            bigCell.appendChild(smallCell);
            small[i][j] ? action(smallCell, small[i][j]) : null;
        }
    } else {
        action(bigCell, big[i]);
    }
}

area.addEventListener('click', (event) => {
    if (event.target.classList.contains("smallCell")) {
        let i = event.target.parentElement.id;
        let j = event.target.id;
        if ((availableBig === -1 || availableBig === i) && small[i][j] === '') {
            small[i][j] = player;
            console.log(player, convertor(i, j));
            classToggle("cell", "lastTurn", "remove");
            if (checkSmallWinner(i)) {
                big[i] = player;
                action(event.target.parentElement, player);
                if (checkBigWinner()) {
                    availableBig = -2;
                    classToggle("bigCell", "available", "remove");
                    classToggle("cell", "lastTurn", "remove");
                    document.querySelectorAll(".bigCell").forEach(element =>
                        (winningCells[element.id]) ? element.classList.add("available") : null);
                    winner = true;
                    return;
                }
            } else {
                action(event.target, player);
            }
            let flag = false;
            small[j].forEach(element => element === '' ? flag = true : null);
            (big[j] !== '' || !flag) ? availableBig = -1: availableBig = j;
            classToggle("bigCell", "available", "remove");
            (availableBig === -1) ? classToggle("bigCell", "available", "add"):
                document.querySelectorAll(".bigCell")[j].classList.add("available");
            player === 'X' ? player = 'O' : player = 'X';
        }
    }
})

const random = () => {
    while (!winner) {
        let i = parseInt(Math.random() * 9, 10);
        let j = parseInt(Math.random() * 9, 10);
        if (document.querySelectorAll(".bigCell")[i].children[j]) {
            document.querySelectorAll(".bigCell")[i].children[j].click();
        }
        let flag = false;
        for (let k = 0; k < 9; k++) {
            if (big[k] === '') {
                for (let l = 0; l < 9; l++) {
                    if (small[k][l] === '') {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            break;
        }
    }
}

const turn = (i, j) => {
    for (let k = 0; k < 9; k++) {
        for (let l = 0; l < 9; l++) {
            if (convertor(k, l)[0] === i && convertor(k, l)[1] === j) {
                document.querySelectorAll(".bigCell")[k].children[l].click();
            }
        }
    }
}
