# Resumo Entrega 01

Trabalho da disciplina de Computação Gráfica. Implementação de um visualizador 2D com Display File, usando Qt e C++.

---

## Objetivo

Implementar um sistema básico de visualização de objetos geométricos (pontos, retas e polígonos) usando a estrutura de **Display File**, onde cada objeto é representado em **coordenadas de mundo** e desenhado na interface gráfica.

---

## Estrutura das Classes

### `Ponto`
Representa uma coordenada 2D no espaço de mundo.
- Atributos: `x`, `y` (float)
- Métodos: `getX()`, `getY()`, `setX()`, `setY()`

---

### `Objeto` *(classe base abstrata)*
Classe pai de todos os objetos geométricos.
- Atributos: `nome` (QString), `tipo` (QString), `pontos` (vector\<Ponto\>)
- Método virtual puro: `desenhar(QPainter&)` — cada subclasse implementa seu próprio desenho
- Todas as subclasses herdam a lista de pontos e os metadados

---

### `ObjetoPonto` → herda de `Objeto`
Representa um ponto desenhável na tela.
- Guarda 1 ponto na lista
- `desenhar()`: plota o ponto diretamente com `drawPoint()`

---

### `Reta` → herda de `Objeto`
Representa uma reta entre dois pontos.
- Guarda 2 pontos na lista
- `desenhar()`: implementa o **algoritmo DDA** (Digital Differential Analyzer) para rasterização ponto a ponto

---

### `Poligono` → herda de `Objeto`
Representa um polígono fechado com N vértices.
- Guarda N pontos na lista
- `desenhar()`: aplica DDA em cada aresta, conectando `pontos[i]` ao `pontos[i+1]`, e fechando com `pontos[n-1]` → `pontos[0]`

---

### `DisplayFile`
Lista central de todos os objetos da cena.
- Atributo: `vector<Objeto*> objetos`
- Método: `adicionar(Objeto*)` — insere um objeto na lista
- O destrutor libera a memória de todos os objetos automaticamente

---

### `AreaDesenho` → herda de `QFrame`
Widget responsável pela área de visualização.
- Contém um `DisplayFile` com os objetos da cena
- Sobrescreve `paintEvent()`: itera o Display File e chama `desenhar()` em cada objeto

---

## Lógica Principal

```
DisplayFile (lista de objetos)
    │
    ├── ObjetoPonto → desenhar() → drawPoint()
    ├── Reta        → desenhar() → DDA ponto a ponto
    └── Poligono    → desenhar() → DDA em cada aresta
            ↓
        AreaDesenho::paintEvent()
            ↓
        QPainter (Qt) — renderiza na tela
```

> **Nota sobre coordenadas:** Nesta entrega, coordenadas de mundo e de tela são coincidentes (mundo limitado ao tamanho da área de desenho). Transformações Window/Viewport serão implementadas em entregas futuras.

---

## 🔧 Requisitos

- [Qt 6](https://www.qt.io/download) (com Qt Creator)
- Compilador C++17 ou superior
- CMake ou qmake

---

## 🚀 Como baixar e executar

### Linux

```bash
# Clonar o repositório
git clone https://github.com/SEU_USUARIO/computacaoGrafica.git
cd computacaoGrafica

# Abrir no Qt Creator
qtcreator .

# OU compilar pelo terminal
mkdir build && cd build
cmake ..
make
./computacaoGrafica
```

### Windows

```bash
# Clonar o repositório (Git Bash ou PowerShell)
git clone https://github.com/SEU_USUARIO/computacaoGrafica.git

# Abrir o Qt Creator
# File > Open Project > selecionar o CMakeLists.txt ou .pro
# Clicar em Configure > Run (▶)
```

> **Dica:** Certifique-se de que o kit do Qt está configurado corretamente no Qt Creator (Projects > Kit Selection).

---

