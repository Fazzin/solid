#include <iostream>
#include <sstream>
#include <string>

class Report {
public:
    Report(const std::string& t, const std::string& d) : title_(std::move(t)), data_(std::move(d)) {}

    const std::string& title() const {return title_;}
    const std::string& data() const {return data_;}

private:
    std::string title_;
    std::string data_;

};

class ProcessingReport {
    public:
        virtual ~ProcessingReport() = default;
        virtual int compute(const std::string& data) const = 0;
};

class ProcessingSum : public ProcessingReport {
    public:
        int compute(const std::string& data) const {
            std::istringstream iss(data);
            int number, sum = 0;
            while(iss >> number) {
                sum += number;
            }
            return sum;
        }
};

class ReportFormat {
    public:
        virtual ~ReportFormat() = default;
        virtual std::string format(const std::string& title, int value) const = 0;
};

class HtmlFormat : public ReportFormat {
    public:
        std::string format(const std::string& title, int value) const override {
            return "<h1>" + title + "</h1>\n<p>" + title + ": " + std::to_string(value) + "</p>";
        }
};

class ReportService {
    public:
        ReportService(const ProcessingReport& p, const ReportFormat& f) : processor_(p), formatter_(f) {}

        std::string render(const Report& r) const {
            int value = processor_.compute(r.data());
            return formatter_.format(r.title(), value);
        }
    private:
        const ProcessingReport& processor_;
        const ReportFormat& formatter_;
};

// Included for demonstration
int main() {
    Report report("Total sales", "51 42 39 60");
    
    ProcessingSum processor;
    HtmlFormat formatter;

    ReportService service(processor, formatter);
    std::cout << service.render(report);
}
