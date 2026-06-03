# 🕵️‍♂️ Detetive de Lore (LoreDB)

Um sistema de gerenciamento relacional construído inteiramente em **C puro**, focado em rastrear o progresso de obras (Animes, Séries, Mangás) e catalogar teorias dos usuários sobre o enredo. 

O projeto foi desenvolvido como um desafio de **Engenharia de Software e Estrutura de Dados**, aplicando conceitos avançados de gerenciamento de memória e persistência em disco sem o uso de bibliotecas externas de banco de dados.

## 🚀 Funcionalidades (CRUD Completo)

* **Create:** Cadastro de Obras (Pais) e Teorias (Filhos).
* **Read:** Listagem geral do banco e detalhamento específico de uma obra e suas teorias.
* **Update:** Atualização de status das teorias cadastradas (ex: de "Em andamento" para "Comprovada").
* **Delete:** Exclusão segura de obras, realizando o *Shift* de vetores contíguos e liberando a memória dos filhos adequadamente para evitar *Memory Leaks*.
* **Persistência (Save/Load):** O estado da memória RAM é serializado e salvo em um arquivo `.txt` ao encerrar o programa, e reconstruído organicamente (com conversões ASCII para Integer e realocações) na próxima execução.

## 🧠 Desafios Técnicos Superados

* **Arquitetura 1:N (Um para Muitos):** Vetores dinâmicos aninhados (uma `struct` contendo um ponteiro dinâmico para um vetor de outras `structs`).
* **Alocação Dinâmica Real:** Uso de `malloc`, `realloc` e `free` controlados pela capacidade atual de cada vetor, dobrando o espaço apenas quando necessário.
* **Ponteiros e Aritmética de Memória:** Navegação segura entre os endereços de memória na construção, busca e deleção.
* **Modularização:** Código separado em `main.c` (UI), `dados.c` (Lógica de Negócio) e `uteis.c` (Funções auxiliares), amarrados por um *header file* (`info.h`).

## 🛠️ Como Compilar e Executar

O projeto pode ser compilado de duas formas, dependendo do seu ambiente.

### Opção 1: Usando GCC (Via Terminal)

Para compilar manualmente usando o GCC, navegue até a raiz do projeto (a pasta "detetive") e passe todos os arquivos `.c` para o compilador:

```bash
# 1. Compilar o projeto
gcc main.c dados.c uteis.c -o detetivelore

# 2. Executar o programa
./detetivelore
```
### Opção 2: Usando CMake
Se você utiliza IDEs como CLion, ou prefere ferramentas modernas de build, o projeto já possui o CMakeLists.txt configurado.

```
# 1. Crie um diretório para o build e entre nele

mkdir build && cd build

# 2. Gere os arquivos de build com o CMake
cmake ..

# 3. Compile o projeto
make

# 4. Execute o programa
./detetivelore
```
### 📂 Estrutura do Projeto
```
main.c: Ponto de entrada, menus interativos e loop principal.

dados.c: Motor do banco de dados (funções CRUD, alocação, save/load).

uteis.c: Tratamento de buffer, formatação e validação de erros.

info.h: Definição das estruturas (LoreDB, Obra, Teoria) e assinaturas.

dados.txt: Arquivo gerado automaticamente para persistência.
```

Desenvolvido com ☕ e muito controle de ponteiros.
