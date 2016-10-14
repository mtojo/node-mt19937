const assert = require('power-assert');
const {rand, srand} = require('..');

describe('mt19937', () => {
  it('should return proper numbers for given seed 0', () => {
    srand(0);
    assert(rand() === 0.5928446165166826);
    assert(rand() === 0.8442657442565983);
    assert(rand() === 0.8579456199898299);
    assert(rand() === 0.8472517373843312);
    assert(rand() === 0.6235636964961083);
    assert(rand() === 0.3843817083737566);
    assert(rand() === 0.2975346053572342);
    assert(rand() === 0.05671297593316366);
    assert(rand() === 0.2726562947415893);
    assert(rand() === 0.4776651117446463);
  });

  it('should return proper numbers for given seed 1', () => {
    srand(1);
    assert(rand() === 0.9971848082302656);
    assert(rand() === 0.9325573613681655);
    assert(rand() === 0.128124447772306);
    assert(rand() === 0.9990405154652736);
    assert(rand() === 0.23608897629816922);
    assert(rand() === 0.3965807261626093);
    assert(rand() === 0.38791074026056105);
    assert(rand() === 0.6697460404470471);
    assert(rand() === 0.9355390727046802);
    assert(rand() === 0.8463109183448406);
  });
});
