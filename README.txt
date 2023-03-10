Proiect: Tema 1
Autor: Chiper Ioana-Cristina
Grupa: 312CD

PART 1 – BITS & PIECES
* Pentru aflarea bitului de pe pozitia x, s-a calculat 2^x prin 1<<x, mentionandu-se ca 1 a fost convertit explicit la tipul uint64_t in prealabil, pentru a obtine rezultatul corect.
* Pentru restul operatiilor se folosesc proprietatile operatorilor pe biti. 
PART 2 – SHUT UP MORTY!
* Pentru aflarea codului unei litere am folosit expresia  <1+’litera_de_codificat’-‘A’>, deoarece are loc o conversie inplicita de la tipul char la tipul de data al numarului 1. De asemenea, acest lucru este posibil deoarece codificarea literelor se realizeaza prin alocarea de numere consecutive (incepand cu 1) literelor in aceeiasi ordine in care acestea apar in alfabet, dar si in tabelul ASCII.
* Pentru a afla litera corespunzatoare unui cod se foloseste  tot observatia de mai sus.
* Pentru codificarea lungimii, bitii care o reprezinta sunt bitii de la pozitia 2 la pozitia 6, iar restul nu conteaza ce valoare au. Se foloaseste acest fapt pentru a constata ca acestia pot fi 0. Initial lunigimea necodificata foloseste biti de la pozitiile 0 pana la 4, deci pentru codificarea ei este suficienta deplasarea spre stanga de doua ori a acestor biti, operatie echivalenta cu <<2. In cazul decodificarii lungimii, se va creea un nou numar folosind doar bitii dintre pozitiile 2 si 6.
* Pentru codificarea a doua caractere se foloseste faptul ca bitii primului caracter vor ocupa doar biti de pe pozitii impare din scrierea codificata, in timp ce bitii celui de al doilea caracter ocupa doar bitii de pe pozitii pare. Astfel pentru primul caracter se observa urmatoarea relatie intre pozitiile bitilor: poz_finala = poz_initiala*2+1, iar in cazul celui de al doilea caracter: poz_finala = poz_initiala*2.
* Pentru decodificarea unui mesaj ce contine doua caractere, se observa din nou o relatie intre pozitia unui bit in forma codificata si cea decodificata, astfel: pentru primul caracter: poz_finala = poz_initiala/2, iar pentr al doilea: poz_finala = poz_initiala/2+4 
PART 3 – TOSS A COIN TO YOUR WITCHER
* O observatie utila este faptul ca numarul format din bitii de la pozitia 0 pana la pozitia x este de fapt restul la impartirea cu 2(x+1)
* Se observa de asemenea ca a^b=0 este echivalent cu a=b. 
* In functia trial_of_the_grasses se observa foarte usor ca o solutie a sistemului (a&c)=(b|c), a&b=0, a|b =c este perechea a=c si b=0; Deoarece nu exista nici o restrictie asupra solutiilor a fost implementata aceasta.
* Alta observatie utila este faptul ca daca un numar in baza doi este alcatuit doar din secvente de x biti activi (numarul 0 este considerat ca fiind alcatuit din 0 astfel de secvente), atunci acesta este divizibil cu numarul format din x biti de 1 consecutivi, incepand cu pozitia 0. Acest lucru se demonstreaza usor, deoarece numarul initial se poate scrie ca o suma de numere ce contin 1 doar pe x pozitii consecutive, acestea putandu-se scrie la randul lor ca numarul format din cei x biti shiftat cu n pozitii.
