// Enrique Macías López A01641402
#include <iostream>
#include <vector>
#include <algorithm>

struct Doll {
    int width;
    int height;
};

// Función de comparación para ordenar las muñecas
bool compare(const Doll &a, const Doll &b) {
    if (a.width == b.width)
        return b.height < a.height; // Altura descendente si el ancho es igual
    return a.width < b.width;       // Ancho ascendente
}

// Función para encontrar el Longest Increasing Subsequence (LIS)
int maxRussianDolls(std::vector<Doll> &dolls) {
    // Extraer las alturas después de ordenar las muñecas
    std::vector<int> heights;
    for (const auto &doll : dolls) {
        heights.push_back(doll.height);
    }

    // Vector para almacenar las alturas del LIS
    std::vector<int> lis;

    for (int height : heights) {
        // Encontrar la posición donde insertar o reemplazar
        auto it = std::lower_bound(lis.begin(), lis.end(), height);
        if (it == lis.end()) {
            // Si la altura es mayor que todas en lis, la agregamos al final
            lis.push_back(height);
        } else {
            // Reemplazamos el primer elemento mayor o igual a height
            *it = height;
        }
    }

    // El tamaño de lis es la cantidad máxima de muñecas que se pueden anidar
    return lis.size();
}

int main() {
    int n;
    // Leer el número de muñecas
    std::cin >> n;

    std::vector<Doll> dolls(n);
    // Leer las dimensiones de las muñecas
    for (int i = 0; i < n; ++i) {
        std::cin >> dolls[i].width >> dolls[i].height;
    }

    // Ordenar las muñecas según los criterios mencionados
    std::sort(dolls.begin(), dolls.end(), compare);

    // Calcular la cantidad máxima de muñecas que se pueden anidar
    int max_dolls = maxRussianDolls(dolls);

    // Imprimir el resultado
    std::cout << max_dolls << std::endl;

    return 0;
}

/* Casos de uso
 *
 * Caso de uso 1:
 * Entrada:
 * 4
 * 5 4
 * 6 4
 * 6 7
 * 2 3
 * Salida esperada:
 * 3
 *
 * Caso de uso 2:
 * Entrada:
 * 5
 * 1 1
 * 1 1
 * 1 1
 * 1 1
 * 1 1
 * Salida esperada:
 * 1
 *
 * Caso de uso 3:
 * Entrada:
 * 5
 * 2 3
 * 5 4
 * 6 7
 * 6 4
 * 7 8
 * Salida esperada:
 * 4
 *
 * Caso de uso 4:
 * Entrada:
 * 6
 * 5 4
 * 6 10
 * 6 7
 * 2 3
 * 7 8
 * 8 9
 * Salida esperada:
 * 5
 */

