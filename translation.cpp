#include <GLFW/glfw3.h>

// Variaveis para guardar a posição do triangulo
float x = 0.0f, y = 0.0f;

void render() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a tela

    // Desenha o triangulo na origem
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    // Desenha o triangulo transladado
    glPushMatrix(); // Salva a matriz atual
    glTranslatef(x, y, 0.0f); // Translada
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glPopMatrix(); // Volta para a matriz salva anteriormente
}

int main() {
    GLFWwindow* window;

    /* Inicializa a biblioteca */
    if (!glfwInit())
        return -1;

    /* Cria uma janela com 800x600 */
    window = glfwCreateWindow(800, 600, "Triangulo Transladado", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Faz o contexto da janela criada o contexto corrente */
    glfwMakeContextCurrent(window);

    /* Loop principal */
    while (!glfwWindowShouldClose(window)) {
        /* Input */
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            y += 0.01f;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            y -= 0.01f;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            x -= 0.01f;
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            x += 0.01f;
        }

        /* Render */
        render();

        /* Troca o front e back buffer */
        glfwSwapBuffers(window);

        /* Checa eventos */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
