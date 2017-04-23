#ifndef XA_SHADERSOURCE_H
#define XA_SHADERSOURCE_H

#include <string>

class ShaderSource {
public:
	virtual std::string getVertexShader() = 0;
	virtual std::string getFragmentShader() = 0;
};

class DefaultShaderSource : public ShaderSource {

public:
	std::string getVertexShader();

	std::string getFragmentShader();

};

#endif // XA_SHADERSOURCE_H