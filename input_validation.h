#pragma once //Dosya bi kere import edildiyse tekrar edilmesi durumunda tekrar okumamak adına kontrol eder.

#include <string>

std::string getMode(); //Kullanıcıya modu sorar ve alır.

std::string getInputFilename(); //Kullanıcıdan input dosyasını alır.

int getKey(); //Kullanıcıdan xor key değerini alır.

std::string generateOutputFilename(const std::string& inputFilename, const std::string& mode);
//Output dosyasını oluşturur ve yeniden isimlendirir.

// Main e include edilecek (main içinde hazırlanan modüldeki fonksiyonları kullanabilemek için)