#include<iostream>
using namespace std;

class XMLData {
    string xmlData;
public:
    XMLData(string pXmlData) {
        xmlData = pXmlData;
    }

    string getXMLData() {
        return xmlData;
    }
};

class DataAnalyticsTool {
    string jsonData;
public:
    DataAnalyticsTool() {}
    DataAnalyticsTool(string pJsonData) {
        jsonData = pJsonData;
    }

    virtual void analyseData() {
        cout << "Analysing JSON Data " << jsonData << endl;
    }
};

class Adapter : public DataAnalyticsTool {
    XMLData* xmlData;
public:
    Adapter(XMLData* pXMLData) {
        xmlData = pXMLData;
    }

    void analyseData() override {
        cout << "Converting XML Data " << xmlData->getXMLData() << " to JSON Data" << endl;
        DataAnalyticsTool::analyseData();
    }
};


class Client {
    public:
        void ProcessData(DataAnalyticsTool* tool) {
            tool->analyseData();
        }
};
    
int main() {
    XMLData* xmlData = new XMLData("Sample XML Data");
    // DataAnalyticsTool* tool = new DataAnalyticsTool(); We dont have JSON data to pass to the tool
    // Pointer type remains same we are just changing the object
    // Adapter should inherit the DataAnalyticsTool
    // Adapter should have Xml data to convert into json data and then analyze it(call analyseData()). Sp pass the xmlData to it.
    DataAnalyticsTool* tool = new Adapter(xmlData);
    Client* client = new Client;
    client->ProcessData(tool);
    return 0;
}
    