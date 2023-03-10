#include "gates.h"

#include <stdio.h>
#include <assert.h>

/* Task 1 - Bit by Bit */

uint8_t get_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint8_t res = -1;

    /* TODO
     *
     * "res" should be 1 if the bit is active, else 0
     */
    res= ((nr>>i) & 1);

    return res;
}


uint64_t flip_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit flipped
     */
    res = nr^((uint64_t)1<<i);

    return res;
}


uint64_t activate_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = 0xFF;

    /* TODO
     *
     * Return the "nr" with the ith bit "1"
     */

    nr = nr|((uint64_t)1<<i);
    res=nr;

    return res;
}


uint64_t clear_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit "0"
     */


    res = ~((~nr)|((uint64_t)1<<i)) ;

    return res;
    
}


/* Task 2 - One Gate to Rule Them All */

uint8_t nand_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    return !(a & b);
}


uint8_t and_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the and gate */

    uint8_t c; // retine valoarea pentru (a NAND b)
    c=nand_gate(a,b);
    res=nand_gate(c,c);

    return res;
}


uint8_t not_gate(uint8_t a)
{
    assert (a == 0 || a == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the not gate */

    res = nand_gate(a,a);

    return res;
}


uint8_t or_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the or gate */

    res = nand_gate(nand_gate(a,a),nand_gate(b,b));

    return res;
}


uint8_t xor_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the xor gate */

    uint8_t c;
    c=nand_gate(a,b);
    res=nand_gate(nand_gate(c,a),nand_gate(c,b));

    return res;
}


/* Task 3 - Just Carry the Bit */

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t c)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);
    assert (c == 0 || c == 1);

    uint8_t res = -1;

    /* TODO - implement the full_adder using the previous gates
     * Since the full_adder needs to provide 2 results, you should
     * encode the sum bit and the carry bit in one byte - you can encode
     * it in whatever way you like
     */

    res = a+b+c;
    /* bitul 0 va reprezenta sum_bit, 
       iar bitul 1 va reprezenta carry_bit
    */

    return res;
}


uint64_t ripple_carry_adder(uint64_t a, uint64_t b)
{
    uint64_t res = -1;

    /* TODO
     * Use the full_adder to implement the ripple carry adder
     * If there is ANY overflow while adding "a" and "b" then the
     * result should be 0
     */

    res = 0;

    uint8_t i; 
    //i= un contor pentru structura repetitiva
    
    uint8_t bit_a_i, bit_b_i;
    // variabile in care pastram bitul de pe pozitia i a celor doua numere
    
    uint8_t sum_and_carry =0;
    uint8_t sum_bit = 0, carry_bit = 0;
    //variabilele sum_bit si carry_bit nu sunt neaparat necesare,
    //dar le folosesc pentru o intelegere mai usoara
    
    for(i=0;i<64;i++)
    {
        bit_a_i = (a>>i) & 1;
        bit_b_i = (b>>i) & 1;
        sum_and_carry = full_adder(bit_a_i,bit_b_i,carry_bit);
        sum_bit = sum_and_carry & 1;
        carry_bit = (sum_and_carry>>1) & 1;
        res += sum_bit<<i;
    }
    if (carry_bit==1)
        res=0;
    // daca bitul de carry este 1 la final inseamna ca suma depaseste 
    // domeniul tipului de data
    return res;
}
