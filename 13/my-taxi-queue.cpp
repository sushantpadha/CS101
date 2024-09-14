#include <string.h>

#include <iostream>

using std::cout, std::cin, std::cerr, std::string;

const int qCap = 6;

struct taxi {
    string id;
    void read() { cin >> id; }
};

struct customer {
    string dest;
    void read() { cin >> dest; }
};

struct taxiQueue {
    // * INVARIANT
    // Q elements stored in Q[begin] ... Q[end-1]
    // Q[end] is the first empty slot

    // * IMPLEMENTATION
    // circular queue
    // involves new reallocation/unnecessary moving of values
    // new taxi queues at the next index `end` modulo 6

    taxi Q[qCap];
    int begin, end;
    bool full;

    void clear();
    bool enqueue(const taxi& t);
    bool dequeue(taxi& t);
    void printQueue();
};

void assign(const taxi& t, const customer& c);

int main() {
    taxiQueue tq;
    tq.clear();

    char in;
    cout << "Enter T for taxi, C for customer, P to print taxi stand\n";

    while (cin >> in, !cin.fail()) {
        taxi t;
        if (in == 'T') {
            t.read();
            if (!tq.enqueue(t))
                cerr << "Could not add taxi " << t.id << '\n';
        } else if (in == 'C') {
            customer c;
            c.read();

            if (!tq.dequeue(t)) {
                cerr << "Could not find taxi for " << c.dest << '\n';
                continue;
            }

            assign(t, c);
        } else if (in == 'P') {
            tq.printQueue();
        } else {
            cerr << "Invalid input. Must be one of T, C, P.\n";
            continue;
        }
    }
}

void taxiQueue::printQueue() {
    cout << "Taxis in stand: ";
    for (int i = begin; (i < end || i >= begin); i = (i + 1) % qCap) {
        cout << "#" << i << " = " << Q[i].id << "; ";
    }
    cout << '\n';
}

void taxiQueue::clear() {
    cout << "\tClearing taxi queue...\n";
    begin = end = 0;
}

bool taxiQueue::enqueue(const taxi& t) {
    if (full) {
        cout << "\tQueue is full!\n";
        printQueue();
        return false;
    }

    cout << "\tEnqueuing taxi " << t.id << '\n';

    // add at end and ++end pointer
    Q[end] = t;
    ++end;
    end %= qCap;

    if (end == begin)
        full = true;
    return true;
}

bool taxiQueue::dequeue(taxi& t) {
    if (end == begin && !full) {
        cout << "\tQueue is empty!\n";
        return false;
    }

    // pop from begin and ++begin pointer
    t = Q[begin];
    ++begin;
    begin % +qCap;

    cout << "\tDequeuing taxi " << t.id << '\n';

    full = false;
    return true;
}

void assign(const taxi& t, const customer& c) {
    cout << "\tAssigning taxi " << t.id << " to customer with dest " << c.dest << '\n';
}
