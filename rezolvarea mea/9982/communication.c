#include "communication.h"
#include "util_comm.h"

#include <stdio.h>


/* Task 1 - The Beginning */

void send_byte_message(void)
{
    /* TODO
     * Send the encoding of the characters: R, I, C, K
     */

    send_squanch(1+'R'-'A');
    send_squanch(1+'I'-'A');
    send_squanch(1+'C'-'A');
    send_squanch(1+'K'-'A');
}


void recv_byte_message(void)
{
    /* TODO
     * Receive 5 encoded characters, decode them and print
     * them to the standard output (as characters)
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */

    uint8_t i; 
    // un contor pentru structura repetitiva
    uint8_t encoded_char;
    // o variabila in care depunem codul caracterului
    char decoded_char;
    //o variabila in care depunem litera decodificata

    for(i=0;i<5;i++)
    {
        encoded_char=recv_squanch();
        decoded_char = 'A' + encoded_char - 1;
        fprintf(stdout,"%c",decoded_char);
    }
}


void comm_byte(void)
{
    /* TODO
     * Receive 10 encoded characters and send each character (the character is
     * still encoded) 2 times
     */

    uint8_t i; 
    // un contor pentru structura repetitiva
    uint8_t encoded_char;
    // o variabila in care depunem codul caracterului
    for(i=0;i<10;i++)
    {
        encoded_char=recv_squanch();
        send_squanch(encoded_char);
        send_squanch(encoded_char);
    }
}


/* Task 2 - Waiting for the Message */

void send_message(void)
{
    /* TODO
     * Send the message: HELLOTHERE
     * - send the encoded length
     * - send each character encoded
     */

    send_squanch(10<<2);
    send_squanch(1+'H'-'A');
    send_squanch(1+'E'-'A');
    send_squanch(1+'L'-'A');
    send_squanch(1+'L'-'A');
    send_squanch(1+'O'-'A');
    send_squanch(1+'T'-'A');
    send_squanch(1+'H'-'A');
    send_squanch(1+'E'-'A');
    send_squanch(1+'R'-'A');
    send_squanch(1+'E'-'A');

}


void recv_message(void)
{
    /* TODO
     * Receive a message:
     * - the first value is the encoded length
     * - length x encoded characters
     * - print each decoded character
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */

    uint8_t lenght_enc,lenght_dec=0,i;
    //variabile pentru lungimea mesajului codificata, respectiv decodificata;
    // i este o variabila pentru structura repetitiva
    uint8_t encoded_char;
    // o variabila in care depunem codul caracterului
    char decoded_char;
    //o variabila in care depunem litera decodificata
    lenght_enc = recv_squanch();
    for(i=2;i<=5;i++)
    {
        lenght_dec += (lenght_enc>>i & 1)<<(i-2);
    }
    fprintf(stdout,"%d",lenght_dec);
    for(i=0;i<lenght_dec;i++)
    {
        encoded_char = recv_squanch();
        decoded_char = 'A' + encoded_char - 1;
        fprintf(stdout,"%c",decoded_char);
    }

    /*
    *   De ce nu scrie in TODO ca trebuie sa afisam si lungimea mesajului??? :< 
    */
}


void comm_message(void)
{
    /* TODO
     * Receive a message from Rick and do one of the following depending on the
     * last character from the message:
     * - 'P' - send back PICKLERICK
     * - anything else - send back VINDICATORS
     * You need to send the messages as you did at the previous tasks:
     * - encode the length and send it
     * - encode each character and send them
     */

    uint8_t lenght_enc,lenght_dec=0,i;
    //variabile pentru lungimea mesajului codificata, respectiv decodificata;
    // i este o variabila pentru structura repetitiva
    uint8_t encoded_char;
    // o variabila in care depunem codul caracterului
    char decoded_char;
    //o variabila in care depunem litera decodificata
    
    lenght_enc = recv_squanch();
    for(i=2;i<=5;i++)
    {
        lenght_dec += (lenght_enc>>i & 1)<<(i-2);
    }

    for(i=0;i<lenght_dec;i++)
    {
        encoded_char = recv_squanch();
        if(i==lenght_dec-1)
            decoded_char = 'A' + encoded_char - 1;
    }

    if(decoded_char == 'P')
    {
        send_squanch(10<<2);
        send_squanch(1+'P'-'A');
        send_squanch(1+'I'-'A');
        send_squanch(1+'C'-'A');
        send_squanch(1+'K'-'A');
        send_squanch(1+'L'-'A');
        send_squanch(1+'E'-'A');
        send_squanch(1+'R'-'A');
        send_squanch(1+'I'-'A');
        send_squanch(1+'C'-'A');
        send_squanch(1+'K'-'A');
    }
    else
    {
        send_squanch(11<<2);
        send_squanch(1+'V'-'A');
        send_squanch(1+'I'-'A');
        send_squanch(1+'N'-'A');
        send_squanch(1+'D'-'A');
        send_squanch(1+'I'-'A');
        send_squanch(1+'C'-'A');
        send_squanch(1+'A'-'A');
        send_squanch(1+'T'-'A');
        send_squanch(1+'O'-'A');
        send_squanch(1+'R'-'A');
        send_squanch(1+'S'-'A');
    }
    
}


/* Task 3 - In the Zone */

void send_squanch2(uint8_t c1, uint8_t c2)
{
    /* TODO
     * Steps:
     * - "merge" the character encoded in c1 and the character encoded in c2
     * - use send_squanch to send the newly formed byte
     */

    uint8_t enc_chrs=0; //encoded characters
    uint8_t i;//contor pentru structura repetitiva

    for(i=0;i<8;i++)
    {
        if(i%2==0)
        {
            enc_chrs += (c2>>(i/2) & 1)<<i;
        }
        else
        {
            enc_chrs += (c1>>(i/2) & 1)<<i;
        }
    }

    send_squanch(enc_chrs);
}


uint8_t decode_squanch2(uint8_t c)
{
    /*
     * Decode the given byte:
     * - split the two characters as in the image from ocw.cs.pub.ro
     */

    uint8_t res = -1;

    /* TODO */

    uint8_t i;
    // o variabila pentru structura repetitiva 
    res = 0;

    for(i=0;i<8;i++)
    {
        if(i%2==0)
            res += ((c>>i)&1)<<(i/2);
        else
            res += ((c>>i)&1)<<(i/2+4);
    }

    return res;
}
