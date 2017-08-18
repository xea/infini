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
    Logger::getDefault()->info(getResult());
}

UniformLocations ShaderProgram::use() {
    glUseProgram(programId);
    return getUniformLocations();
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

unsigned int ShaderProgram::getUniformLocation(UniformType type) {
    unsigned int uniformLocation;

    switch (type) {
        case UniformType::TransformationMatrix:
            uniformLocation = glGetUniformLocation(programId, "transformation");
            break;
    }

    return uniformLocation;
}

UniformLocations ShaderProgram::getUniformLocations() {
    UniformLocations locations;

    locations.transformation = getUniformLocation(UniformType::TransformationMatrix);

    return locations;
}

std::shared_ptr<ShaderProgram> ShaderProgram::getDefault() {
    std::shared_ptr<ShaderProgram> program = std::make_shared<ShaderProgram>();

    Shader vs = Shader::loadShader("default.vs", ShaderType::VertexShader);
    Shader fs = Shader::loadShader("default.fs", ShaderType::FragmentShader);

    program->attachShader(vs);
    program->attachShader(fs);
    program->link();

    return program;
}