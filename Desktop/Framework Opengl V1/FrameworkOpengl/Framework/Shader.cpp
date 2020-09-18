#include "Shader.h"






// default
Shader::Shader(): shaderProgram()
{

}

Shader::~Shader()
{
}

void Shader::InitShaders(const char* vertexShaderPath, const char* fragShaderPath)
{
    CompilerShaders(vertexShaderPath, fragShaderPath);
}

// generate using vertex and frag shaders
void Shader::CompilerShaders(const char* vertexShaderPath, const char* fragShaderPath) {
    int success;
    char infoLog[512];

    // compile shaders
    GLuint vertexShader = compileShader(vertexShaderPath, GL_VERTEX_SHADER);
    GLuint fragShader = compileShader(fragShaderPath, GL_FRAGMENT_SHADER);

    // create program and attach shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    // linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Linking error:" << std::endl << infoLog << std::endl;
    }

    // delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

// activate shader
void Shader::activate() {
    glUseProgram(shaderProgram);
}

/*
    utility functions
*/

// load string from file
std::string Shader::loadShaderSrc(const char* filePath) {
    std::ifstream file;
    std::stringstream buf;

    std::string ret = "";

    // open file
    file.open(filePath);

    if (file.is_open()) {
        // read buffer
        buf << file.rdbuf();
        ret = buf.str();
    }
    else {
        std::cout << "Could not open " << filePath << std::endl;
    }

    // close file
    file.close();

    return ret;
}

// compile shader program
GLuint Shader::compileShader(const char* filePath, GLuint type) {
    int success;
    char infoLog[512];

    // create shader from file
    GLuint ret = glCreateShader(type);
    std::string shaderSrc = loadShaderSrc(filePath);
    const GLchar* shader = shaderSrc.c_str();
    glShaderSource(ret, 1, &shader, NULL);
    glCompileShader(ret);

    // catch compilation error
    glGetShaderiv(ret, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(ret, 512, NULL, infoLog);
        std::cout << "Error with shader comp.:" << std::endl << infoLog << std::endl;
    }

    return ret;
}


// set uniform variables


void Shader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void Shader::SetFloat4f(const std::string& name, float v1, float v2, float v3, float v4) const
{

    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), v1, v2, v3, v4);
}

void Shader::setVec2(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setVec2(const std::string& name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(shaderProgram, name.c_str()), x, y);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z);
}

void Shader::setVec4(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMat3(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetMat4(const std::string& name, glm::mat4 value) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
