```
int main() {
    bitset<8> bt;

    bt.set();
    bt.flip();
    bt.reset();
    bt.flip();

    bt.reset(4);
    cout << bt.all() << endl;
    cout << bt.any() << endl;
    cout << bt << " " << bt.count() << endl;
    bt.reset();
    cout << bt.none() << endl;
    bt.flip(0);
    cout << bt.test(0) << endl;

    // all => if all bits is set then return zero otherwise false
    // any => if any bit is set then return true
    // count => count all the set bits
    // flip => flip all the bits or if position given then flip that bit
    // none => if none of bits are set then return true otherwise false
    // set => set a particular bit or set all bit
    // reset => reset a particular bit or all bits
    // size => size of bitset
    // test => check if the bit is set at position 0 or 1

}
```
