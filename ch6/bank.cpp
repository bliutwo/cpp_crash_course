#include <cstdio>
#include <stdexcept>
#include <cstring>

// https://stackoverflow.com/questions/18199744/data-member-vec-cannot-be-a-member-template
// The template <> statement is only used when **declaring** a *function template* or a *class template*.
template <typename T>
struct AccountDatabase {
    virtual double retrieve_amount() = 0;
    virtual void set_amount(double new_amount) = 0;
    virtual T get_id() = 0;
};

// https://stackoverflow.com/questions/5693954/c-error-expected-class-name-before-token-when-inheriting-a-template-cl
// You need to inherit from the concrete class, i.e. from AccountDatabase<T>, not merely AccountDatabase
template <typename T>
struct InMemoryAccountDatabase : AccountDatabase<T> {
    InMemoryAccountDatabase(T id, double amount) : id{ id }, amount{ amount } {}
    double retrieve_amount() override {
        return amount;
    }

    void set_amount(double new_amount) override {
        amount = new_amount;
    }

    T get_id() override {
        return id;
    }
private:
    T id;
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

struct Account {
    Account() : balance{} {}
    double get_balance() {
        return balance;
    }
    void add_to_balance(double additive) {
        balance += additive;
    }
    void subtract_from_balance(double subtractive) {
        balance -= subtractive;
    }
private:
    double balance;
};

template <typename T>
struct Bank {
    Bank(Logger* logger, AccountDatabase<T>& db) : logger{ logger }, db{ db } {}
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }

    void make_transfer(long from, long to, double amount) {
        if (logger) logger->log_transfer(from, to, amount);
    }
private:
    Logger* logger{};
    AccountDatabase<T>& db;
};

int main() {
    ConsoleLogger console_logger("wow");
    FileLogger file_logger;
    InMemoryAccountDatabase<long> db(1, 0.0);
    Bank<long> bank(nullptr, db);
    bank.set_logger(&console_logger);
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);
    return 0;
}

int main1() {
    //InMemoryAccountDatabase<Account> db(1, 0.0);
    //Bank<Account> bank(nullptr, db);
    return 0;
}
