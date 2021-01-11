//AUTORE: Alberto Penzo

#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
    Event(double t)
        : time{t} {}

    virtual ~Event() {}

    virtual void do_event() = 0;

    virtual double get_time() { return time; }

protected:
    double time;
};

#endif