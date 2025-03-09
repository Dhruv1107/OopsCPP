#include <iostream>

struct Document {
    std::string content;
};

struct IPrinter {
    virtual void print(Document& doc) = 0;
    virtual ~IPrinter() = default;
};

struct IScanner {
    virtual void scan(Document& doc) = 0;
    virtual ~IScanner() = default;
};

struct Printer : IPrinter {
    void print(Document& doc) override {
        std::cout << "Printing document: " << doc.content << std::endl;
    }
};

struct Scanner : IScanner {
    void scan(Document& doc) override {
        std::cout << "Scanning document: " << doc.content << std::endl;
    }
};

struct IMachine : IPrinter, IScanner {
    virtual ~IMachine() = default;
};

struct Machine : IMachine {
    IPrinter& printer;
    IScanner& scanner;

    Machine(IPrinter& printer, IScanner& scanner)
        : printer{printer}, scanner{scanner} {}

    void print(Document& doc) override {
        printer.print(doc);
    }

    void scan(Document& doc) override {
        scanner.scan(doc);
    }
};

int main() {
    Document doc{"Interface Segregation Principle Example"};

    Printer printer;
    Scanner scanner;
    Machine machine(printer, scanner);

    machine.print(doc);
    machine.scan(doc);

    return 0;
}
