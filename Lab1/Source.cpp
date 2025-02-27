#include "header.h"

int Sum(int a, int b) { return a + b; } // simbolulire matematice erau amestecate
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; } //aici am pus la toate int int pt ca erau erori la linkere

int main(int argc, char* argv[])
{
    char input[100] = "---H***E+++L+++L///O---P+++O/+-**O---"; //aici nu era [7] am schimbat
    func Operatori[4] = { Sum, Dif, Mul, Div }; //am sters 65 si 0
    int S, V;  S = 0;//s trb initializat
    Content x;//  x nu poate fi egal cu 15 fiind struct
    int idx; //idx trb sa fie int nu double

    for (int i = 0; i < strlen(input); i++) //aici nu era int
    {
        switch (input[i] - 42)
        {
        case INMULTIRE:
            idx = 2;
            x.p1 = 3;
            x.p2 = 3;
            break;
        case SUMA:
            idx = 0;
            x.p1 = 7;
            x.p2 = 5;
            break;
        case DIFERENTA:
            idx = 1;
            x.p1 = 10;
            x.p2 = 1;
            break;
        case IMPARTIRE:
            idx = 3;
            x.p1 = 8;
            x.p2 = 4;
            break; //toate caseurile nu aveau break
        }

        S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}