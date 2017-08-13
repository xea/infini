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

ShaderProgram ShaderProgram::getDefault() {
    ShaderProgram program;

    Shader vs = Shader::loadShader("", ShaderType::VertexShader);
    Shader fs = Shader::loadShader("", ShaderType::FragmentShader);

    program.attachShader(vs);
    program.attachShader(fs);
    program.link();

    return program;
}