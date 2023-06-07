#if _WIN32
#include <C:\\raylib\\raylib\\src\\raylib.h>
#include <io.h> // equivalent to <unistd.h>
#elif __linux__
#include <raylib.h>
#include <unistd.h> // equivalent to <io.h>
#endif

#if _WIN32
#include "../ext/glew-2.1.0/include/GL/glew.h"
#include "../ext/glfw-3.3.8/include/GLFW/glfw3.h"
// #include <GL/glew.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#elif __linux__
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// #include <glad/gl.h> // Use `glad` for `raylib`
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

typedef struct ImagePosition {
  int x, y;
} ImagePosition;

typedef struct ImageName {
  const char *name;
} ImageName;

typedef struct VertexPoints {
  GLfloat a2[3];
  GLfloat b2[3];
  GLfloat c2[3];
} VertexPoints;

int initialise_Trig_VBOs() {
  struct VertexPoints {
    GLfloat a2[3];
    GLfloat b2[3];
    GLfloat c2[3];
  } vertices = {

      .a2 =
          {
              .0f,
              .2f,
              .0f,
          },
      .b2 =
          {
              .2f,
              .1f,
              .0f,
          },
      .c2 = {
          .1f,
          .1f,
          .0f,
      }};

  return 0;
}

int *transform_A2_Buffers(VertexPoints a2_Buffers) {
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(a2_Buffers.a2), a2_Buffers.a2,
               GL_STATIC_DRAW);

  return &a2_Buffers.a2;
}

int *transform_B2_Buffers(VertexPoints b2_Buffers) {
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(b2_Buffers.b2), b2_Buffers.b2,
               GL_STATIC_DRAW);

  return &b2_Buffers.b2;
}

int *transform_C2_Buffers(VertexPoints c2_Buffers) {
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(c2_Buffers.c2), c2_Buffers.c2,
               GL_STATIC_DRAW);

  return &c2_Buffers.c2;
}

int transpose(GLuint vbo) {
  GLuint vao = 0;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

  // ImagePosition *img_pos1;
  // glVertex2i(img_pos1->x, img_pos1->y);

  return 0;
}

int render(GLuint vao) {
  const char *vertex_shader = "#version410\n"
                              "in vec3 vp;"
                              "void main () {"
                              "\tgl_Position = vec4 (vp, 1.0);"
                              "}";

  const char *fragment_shader = "#version410\n"
                                "in vec4 frag;"
                                "void main () {"
                                "\tfrag = vec4 (.5, .0, .0, 1.0);"
                                "}";

  GLuint vx = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vx, 1, &vertex_shader, NULL);
  glCompileShader(vx);
  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fs, 1, &fragment_shader, NULL);
  glCompileShader(fs);

  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, fs);
  glAttachShader(shader_program, vx);
  glLinkProgram(shader_program);

  BeginDrawing();
/*! TODO: I forgor...
 *
 * @todo Cure my dementia.
 */
// Clear rendering viewpoint's surface's buffers
#if !glfwWindowShouldClose
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#elif !WindowShouldClose
  ClearBackground(BLANK);
#endif
  glUseProgram(shader_program);
  glBindVertexArray(vao);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glfwPollEvents();

  GLFWimage animation_idxs[8];
  GLFWimage spritesheet_pngs[8];
  for (int idx = 0; idx < sizeof(animation_idxs); idx++) {
    animation_idxs[idx] = spritesheet_pngs[idx];
  }

  EndDrawing();

  return 0;
}

int init() { // create
  const char *description;
  int ret_val = glfwGetError(&description);

  if (description)
    fprintf(stderr, "GLFW Error occurred: %s\n", description);

  if (ret_val != GLFW_NO_ERROR) {
    fprintf(stderr, "GLFW Error occured[!] --- GLFW3 encountered an error\n");
    ret_val = 0;
  }

  if (!glfwInit()) {
    fprintf(stderr, "GLFW Error occured[!] --- could not start GLFW3\n");
    ret_val = -1;
  }

  GLFWwindow *window =
      glfwCreateWindow(600, 480, "Damage GL VFX Test!", NULL, NULL);

  if (!window) {
    fprintf(stderr, "GLFW Error occured[!] --- could not start GLFW3\n");
    glfwTerminate();
    ret_val = -1;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  glewInit();

  glEnable(GL_DEPTH_TEST); // enable depth-testing
  glDepthFunc(GL_LESS);

  printf("Compiled against GLFW %i.%i.%i\n", GLFW_VERSION_MAJOR,
         GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

  while (!glfwWindowShouldClose(window)) {
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Running against GLFW %i.%i.%i\n", major, minor, revision);

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return ret_val;
}
