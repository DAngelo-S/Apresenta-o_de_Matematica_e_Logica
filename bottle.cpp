#include<bits/stdc++.h>

using namespace std;

int main () {
    int garrafas;
    cin >> garrafas;

    float peso[garrafas];
    float soma = 0, soma_esperada = 0;

    for (int i = 0; i < garrafas; i++) {
        cin >> peso[i];
        soma += (i+1) * peso[i];
        soma_esperada += (i+1); // lembrete: cada garrafa comum tem 1.0 de peso
    }

    /* O que acontece se tirarmos o ceil ? Teste a entrada:
        3
        1.1 1 1
    */
    cout << "A garrafa " << ceil((soma - soma_esperada) / 0.1) << " é a mais pesada\n.";

    return 0;

}