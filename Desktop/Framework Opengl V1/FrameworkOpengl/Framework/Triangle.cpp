#include"Triangle.h"
#include"Shader.h"



Triangle::Triangle(): VBO(), VAO(), EBO()
{                                                              
}

Triangle::~Triangle()
{
}

void Triangle::Initialized()
{
    

    float vertices[] =
    {

       -0.5f,  -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
        0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,   0.5f, 0.0f,  0.0f, 0.0f, 1.0f

    };

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //-----------------------        end model        ------------------------------//


    
}

void Triangle::Update()
{
    
}

void Triangle::Draw(ShaderManager shader)
{

    shader.GetShader()->SetFloat4f("color", 0.5f, 1.0f, 0.5f, 1.0f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::ShutDown()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
   
}
