#include <cstdio>
#include <stdexcept>
#include <cstring>

struct AccountDatabase {
    virtual double retrieve_amount() = 0;
    virtual void set_amount(double new_amount) = 0;
    virtual long get_id() = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
    InMemoryAccountDatabase(long id, double amount) : id{ id }, amount{ amount } {}
    double retrieve_amount() override {
        return amount;
    }

    void set_amount(double new_amount) override {
        amount = new_amount;
    }

    long get_id() override {
        return id;
    }
private:
    long id;
    double amount;
};

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    ConsoleLogger(const char* s) {
        prefix = new char[strlen(s)];
        strncpy(prefix, s, strlen(s));
    }
    ~ConsoleLogger() {
        printf("Deleting prefix\n");
        delete[] prefix;
    }
    void log_transfer(long from, long to, double amount) override {
        printf("%s: [cons] %ld -> %ld: %f\n", prefix, from, to, amount);
    }
    char* prefix;
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }
};

struct Bank {
    Bank(Logger* logger, AccountDatabase& db) : logger{ logger }, db{ db } {}
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }

    void make_transfer(long from, long to, double amount) {
        if (logger) logger->log_transfer(from, to, amount);
    }
private:
    Logger* logger{};
    AccountDatabase& db;
};

int main() {
    ConsoleLogger console_logger("wow");
    FileLogger file_logger;
    InMemoryAccountDatabase db(1, 0.0);
    Bank bank(nullptr, db);
    bank.set_logger(&console_logger);
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);
    return 0;
}
