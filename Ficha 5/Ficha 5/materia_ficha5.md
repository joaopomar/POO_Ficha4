# Matéria - Ficha 5: Gestão de Recursos Dinâmicos e Composição com Memória Dinâmica

## 1. Memória Dinâmica em C++

### 1.1 Alocação e Libertação de Memória
```cpp
// Alocação de memória dinâmica
int* ptr = new int;           // Aloca um inteiro
int* arr = new int[10];       // Aloca array de 10 inteiros

// Libertação de memória
delete ptr;                    // Liberta um objeto
delete[] arr;                  // Liberta um array
```

**Regra fundamental:** Toda memória alocada com `new` deve ser libertada com `delete`, e toda memória alocada com `new[]` deve ser libertada com `delete[]`.

### 1.2 Memory Leaks
Um *memory leak* ocorre quando memória alocada dinamicamente não é libertada. Isto causa:
- Desperdício de memória
- Degradação do desempenho
- Possível crash da aplicação

## 2. A Regra dos Três (Rule of Three)

Quando uma classe gere recursos dinâmicos, é necessário implementar:

1. **Destrutor** (`~ClassName()`)
2. **Construtor por Cópia** (`ClassName(const ClassName&)`)
3. **Operador de Atribuição** (`operator=`)

### 2.1 Destrutor
Responsável por libertar recursos quando o objeto é destruído.

```cpp
class MyString {
    char* data;
    
public:
    ~MyString() {
        delete[] data;  // Liberta a memória alocada
    }
};
```

**Quando é chamado:**
- Fim do scope de uma variável local
- `delete` em ponteiros
- Fim do programa

### 2.2 Construtor por Cópia
Cria uma cópia profunda (*deep copy*) do objeto.

```cpp
class MyString {
    char* data;
    int tamanho;
    
public:
    // Construtor por cópia
    MyString(const MyString& outro) {
        tamanho = outro.tamanho;
        data = new char[tamanho + 1];
        strcpy(data, outro.data);
    }
};
```

**Quando é chamado:**
- Passagem por valor para funções
- Retorno por valor de funções
- Inicialização: `MyString b = a;`

**Cópia Superficial vs Profunda:**
- *Shallow copy*: Copia apenas ponteiros (PERIGOSO com recursos dinâmicos)
- *Deep copy*: Aloca nova memória e copia conteúdo

### 2.3 Operador de Atribuição
Atribui o conteúdo de um objeto a outro já existente.

```cpp
class MyString {
    char* data;
    int tamanho;
    
public:
    // Operador de atribuição
    MyString& operator=(const MyString& outro) {
        if (this == &outro)  // Proteção contra auto-atribuição
            return *this;
        
        delete[] data;  // Liberta memória antiga
        
        tamanho = outro.tamanho;
        data = new char[tamanho + 1];
        strcpy(data, outro.data);
        
        return *this;
    }
};
```

**Quando é chamado:**
- Atribuição: `a = b;`

**Diferença para construtor por cópia:**
- Operador de atribuição trabalha com objeto já construído (precisa libertar recursos antigos)
- Construtor por cópia trabalha com objeto novo

## 3. Idioma Copy-and-Swap

Técnica elegante para implementar o operador de atribuição de forma exception-safe.

```cpp
class MyString {
    char* data;
    int tamanho;
    
    void swap(MyString& outro) {
        std::swap(data, outro.data);
        std::swap(tamanho, outro.tamanho);
    }
    
public:
    // Operador de atribuição usando swap
    MyString& operator=(MyString outro) {  // Passa por CÓPIA
        swap(outro);
        return *this;
    }
};
```

**Vantagens:**
- Exception-safe
- Código mais limpo
- Evita auto-atribuição automaticamente
- Reutiliza o construtor por cópia

**Como funciona:**
1. O parâmetro `outro` é passado por cópia (usa construtor por cópia)
2. Troca conteúdo entre `this` e `outro`
3. `outro` é destruído no fim (levando os dados antigos de `this`)

## 4. Semântica Move (C++11)

Otimização para quando o objeto fonte é temporário.

### 4.1 Referências RValue
```cpp
int&& rref = 5;  // RValue reference - referência a temporários
```

### 4.2 Construtor por Cópia Move
```cpp
class MyString {
    char* data;
    int tamanho;
    
public:
    // Construtor move
    MyString(MyString&& outro) noexcept {
        data = outro.data;
        tamanho = outro.tamanho;
        
        outro.data = nullptr;  // "Rouba" os recursos
        outro.tamanho = 0;
    }
};
```

### 4.3 Operador de Atribuição Move
```cpp
MyString& operator=(MyString&& outro) noexcept {
    if (this == &outro)
        return *this;
    
    delete[] data;  // Liberta recursos antigos
    
    data = outro.data;
    tamanho = outro.tamanho;
    
    outro.data = nullptr;
    outro.tamanho = 0;
    
    return *this;
}
```

**Quando usar:**
- Objeto fonte é temporário (vai ser destruído)
- Move é mais eficiente que copiar (apenas troca ponteiros)

**Regra dos Cinco:**
Com semântica move, são necessários:
1. Destrutor
2. Construtor por cópia
3. Operador de atribuição
4. Construtor move
5. Operador de atribuição move

## 5. Classes Interiores (Nested Classes)

Classes definidas dentro de outras classes.

```cpp
class ArmarioFichas {
public:
    // Classe interior
    class DadosCliente {
    public:
        string nome;
        int numConsultas;
        
        DadosCliente(string n, int nc) : nome(n), numConsultas(nc) {}
    };
    
    DadosCliente obtemDados(int nif) const;
};

// Uso:
ArmarioFichas::DadosCliente dados = armario.obtemDados(123456);
```

**Quando usar:**
- A classe interior só faz sentido no contexto da classe exterior
- Agrupar dados relacionados
- Encapsulamento (esconder detalhes de implementação)

## 6. Gestão de Coleções Dinâmicas

### 6.1 Array Dinâmico de Objetos

```cpp
class ArmarioFichas {
    Cliente** clientes;  // Array de ponteiros para Cliente
    int numClientes;
    int capacidade;
    
public:
    ArmarioFichas() : clientes(nullptr), numClientes(0), capacidade(0) {}
    
    void adicionar(const string& nome, int nif) {
        if (numClientes == capacidade) {
            // Redimensionar
            int novaCapacidade = (capacidade == 0) ? 1 : capacidade * 2;
            Cliente** novo = new Cliente*[novaCapacidade];
            
            for (int i = 0; i < numClientes; i++)
                novo[i] = clientes[i];
            
            delete[] clientes;
            clientes = novo;
            capacidade = novaCapacidade;
        }
        
        clientes[numClientes++] = new Cliente(nome, nif);
    }
    
    ~ArmarioFichas() {
        for (int i = 0; i < numClientes; i++)
            delete clientes[i];
        delete[] clientes;
    }
};
```

### 6.2 Otimização de Alocação

Alocar memória em blocos para reduzir chamadas a `new`:

```cpp
class MyString {
    static const int BLOCO = 16;  // Múltiplo de alocação
    char* data;
    int tamanhoUsado;     // Caracteres em uso
    int tamanhoAlocado;   // Memória alocada
    
public:
    void acrescenta(const char* str) {
        int novoTamanho = tamanhoUsado + strlen(str);
        
        if (novoTamanho + 1 > tamanhoAlocado) {
            // Alocar em múltiplos de BLOCO
            int novaCapacidade = ((novoTamanho + 1 + BLOCO - 1) / BLOCO) * BLOCO;
            char* novo = new char[novaCapacidade];
            
            if (data) {
                strcpy(novo, data);
                delete[] data;
            }
            
            data = novo;
            tamanhoAlocado = novaCapacidade;
        }
        
        strcat(data, str);
        tamanhoUsado = novoTamanho;
    }
};
```

## 7. Boas Práticas

### 7.1 Inicialização
```cpp
// BOM: Inicializar ponteiros
char* data = nullptr;

// MAU: Ponteiro não inicializado
char* data;  // Contém lixo
```

### 7.2 Proteção contra Auto-atribuição
```cpp
MyString& operator=(const MyString& outro) {
    if (this == &outro)  // IMPORTANTE!
        return *this;
    // ... resto do código
}
```

### 7.3 Validação de Índices
```cpp
bool mudaCharAt(int indice, char c) {
    if (indice < 0 || indice >= tamanho)
        return false;  // Índice inválido
    
    data[indice] = c;
    return true;
}
```

### 7.4 Usar const Corretamente
```cpp
const char* obtemCString() const {
    return data;  // Retorna para leitura, não modificação
}
```

## 8. Checklist para Classes com Recursos Dinâmicos

- [ ] Destrutor implementado e liberta toda a memória
- [ ] Construtor por cópia faz deep copy
- [ ] Operador de atribuição:
  - [ ] Verifica auto-atribuição
  - [ ] Liberta recursos antigos
  - [ ] Aloca novos recursos
  - [ ] Retorna `*this`
- [ ] Sem memory leaks
- [ ] Sem acessos a memória inválida
- [ ] Ponteiros inicializados (nullptr)
- [ ] Validação de índices/parâmetros
- [ ] (Opcional) Semântica move implementada

## 9. Exemplo Completo: MyString Simples

```cpp
class MyString {
    char* data;
    int tamanho;
    
public:
    // Construtor padrão
    MyString() : data(new char[1]), tamanho(0) {
        data[0] = '\0';
    }
    
    // Construtor com string
    MyString(const char* str) {
        tamanho = strlen(str);
        data = new char[tamanho + 1];
        strcpy(data, str);
    }
    
    // Destrutor
    ~MyString() {
        delete[] data;
    }
    
    // Construtor por cópia
    MyString(const MyString& outro) {
        tamanho = outro.tamanho;
        data = new char[tamanho + 1];
        strcpy(data, outro.data);
    }
    
    // Operador de atribuição
    MyString& operator=(const MyString& outro) {
        if (this == &outro)
            return *this;
        
        delete[] data;
        
        tamanho = outro.tamanho;
        data = new char[tamanho + 1];
        strcpy(data, outro.data);
        
        return *this;
    }
    
    // Métodos auxiliares
    const char* obtemCString() const {
        return data;
    }
    
    void acrescenta(const char* str) {
        int novoTamanho = tamanho + strlen(str);
        char* novo = new char[novoTamanho + 1];
        
        strcpy(novo, data);
        strcat(novo, str);
        
        delete[] data;
        data = novo;
        tamanho = novoTamanho;
    }
};
```

## 10. Resumo dos Conceitos Principais

1. **Memória Dinâmica**: `new`/`delete` para alocação flexível
2. **Regra dos Três**: Destrutor, construtor cópia, operador atribuição
3. **Deep Copy**: Copiar conteúdo, não ponteiros
4. **Idioma Swap**: Técnica para operador de atribuição eficiente
5. **Semântica Move**: Otimização para temporários (Regra dos Cinco)
6. **Classes Interiores**: Encapsulamento de dados relacionados
7. **Gestão de Coleções**: Arrays dinâmicos que crescem conforme necessário
8. **RAII**: Resource Acquisition Is Initialization - recursos geridos pelo ciclo de vida do objeto

