const int A = 12;
const int B = 13;
const int C = 9;
const int E = 7;
const int D = 8;
const int F = 11;
const int G = 10;

void displayLetter(char letter){
  switch(letter) {
    case 'A':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'B':
        digitalWrite(A, 0);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'C':
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case 'D':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 1);
        break;
    case 'E':
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'F':
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'G':
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case 'H':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'I':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    case 'J':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    case 'K':
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'L':
        digitalWrite(A, 0);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case 'M':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case 'N':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'O':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case 'P':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 0);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'Q':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'R':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 0);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'S':
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 0);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'T':
        digitalWrite(A, 0);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    case 'U':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case 'V':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    case 'W':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    case 'X':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'Y':
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 0);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 'Z':
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 0);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 1);
        break;
    default:
        digitalWrite(A, 0);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
}

}

void setup() {
  // put your setup code here, to run once:
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(E,OUTPUT);
pinMode(F,OUTPUT);
pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
displayLetter('A');
    delay(1000);
    displayLetter('P');
    delay(1000);
    displayLetter('P');
    delay(1000);
    displayLetter('L');
    delay(1000);
    displayLetter('E');
    delay(1000);
}
