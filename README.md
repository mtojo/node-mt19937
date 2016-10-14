# node-mt19937

Generates a better random number for Node.js.

## Installation

```bash
npm install --save https://github.com/mtojo/node-mt19937.git
```

## Usage

```js
const {rand, srand} = require('mt19937');
srand(Math.floor(Math.random() * 100000000));
const n = rand();
```

## License

MIT
