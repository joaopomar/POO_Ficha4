#include <map>
#include <string>
#include <initializer_list>
using namespace std;

map<string, int> contaOcorrencias(initializer_list<string> votos) {
    // 1. Criar um map vazio para guardar as contagens
    map<string, int> contagens;

    // 2. Percorrer a lista de nomes (votos)
    //    - Para cada nome, incrementar a contagem no map
    for (const auto& voto : votos) {
        contagens[voto]++;
    }
    
    // 3. Encontrar o número máximo de votos
        int maximo = 0;
    
    for (const auto& par : contagens) {
        if (par.second > maximo) {
            maximo = par.second;
        }
    }
    
    // 4. Criar um novo map para o resultado
    map<string, int> resultado;
    
    //    - Percorrer o map de contagens
    for (const auto& par : contagens) {
        //    - Se a contagem == máximo, adiciona "_VENCEU" ao nome
        if (par.second == maximo) {
            resultado[par.first + "_VENCEU"] = par.second;
        }
        //    - Senão, copia como está
        else {
            resultado[par.first] = par.second;
        }
    }
    
    // 5. Retornar o map resultado
    return resultado;
}