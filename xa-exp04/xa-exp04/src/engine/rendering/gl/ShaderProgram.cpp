#include <engine/rendering/gl/ShaderProgram.h>

ShaderProgram::ShaderProgram() {
    programId = glCreateProgram();
}

void ShaderProgram::attachShader(Shader shader) {
    glAttachShader(programId, shader.getShaderId());
}

void ShaderProgram::deleteShader(Shader shader) {
    glDeleteShader(shader.getShaderId());
}

void ShaderProgram::link() {
    glLinkProgram(programId);
}

void ShaderProgram::use() {
    glUseProgram(programId);
}

string ShaderProgram::getResult() {
    string result;
    int success;
    char infoLog[512];
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programId, 512, NULL, infoLog);
         result.append("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
         result.append(infoLog); 
    }

    return result;
}

ShaderProgram ShaderProgram::getDefault() {
    ShaderProgram program;

    Shader vs = Shader::loadShader("", ShaderType::VertexShader);
    Shader fs = Shader::loadShader("", ShaderType::FragmentShader);

    program.attachShader(vs);
    program.attachShader(fs);
    program.link();

    return program;
}