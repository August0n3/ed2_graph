#include <stdio.h>
#include <stdlib.h>

struct Grafo{
    int num_vertices;
    int **arestas;
};

typedef struct Grafo grafo;

//funcao de criar grafo
grafo *criar_grafo(int num_vertices){
    int i, j;
    grafo *g = malloc(sizeof(grafo));
    if(g == NULL){
        return NULL;
    }

    g->num_vertices = num_vertices;

    g->arestas = calloc(sizeof(int*), g->num_vertices);
    
    if (g->arestas == NULL){
        free(g);
        return NULL;
    }

    for (i = 0; i < g->num_vertices;i++){
            g->arestas[i] = calloc(sizeof(int*), g->num_vertices);
            
        }
    
    return g;
}





void exibir_grafo(grafo *g){
    int i, j;
    
    printf("Grafo{\n");

    for (i = 1; i < g->num_vertices; i++){
        for (j = 1; j < g->num_vertices; j++){
        printf("%d ", g->arestas[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}

int adicionar_aresta(grafo *g, int vertice_saida, int vertice_entrada){

    if(checar_arestas(g,vertice_saida,vertice_entrada)){
        return 0;
    }

    g->arestas[vertice_saida][vertice_entrada] += 1;
    g->arestas[vertice_entrada][vertice_saida] += 1;
    

    return 1;
}

int checar_arestas(grafo *g, int vertice_saida, int vertice_entrada){
    return (g->arestas[vertice_saida][vertice_entrada]);
}

int main(){
    grafo *g1 = criar_grafo(40);
    int k = 0;
    int c =0 ;
    FILE *dados = fopen("road-chesapeake.csv","r");

    while (fscanf(dados,"%d;%d;\n",&k,&c) == 2){
        adicionar_aresta(g1,k,c);
    }
    
    exibir_grafo(g1);

    return 0;
}