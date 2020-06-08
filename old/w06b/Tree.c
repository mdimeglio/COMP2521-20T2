bool ScheduleAdd(Schedule s, Time t) {
    Time start = TimeSubtractMinutes(t, 10);
    Time end = TimeAddMinutes(t, 10);
    Time startCeil = TreeCeiling(s->times, start);
    Time endFloor = TreeFloor(s->times, end);
    bool success = false;
    if ((startCeil == NULL || TimeCmp(startCeil, end) > 0) &&
        (endFloor == NULL || TimeCmp(endFloor, start) < 0)) {
        TreeInsert(s->times, t);
        s->count++;
        success = true;
    }
    TimeFree(start);
    TimeFree(end);
    TimeFree(startCeil);
    TimeFree(endFloor);
    return success;
}




Time TreeFloor(Tree t, Time time) {
    if (t == NULL) {
        return NULL;
    } else if (TimeCmp(time, t->time) == 0) {
        return t->time;
    } else if (TimeCmp(time, t->time) < 0) {
        return TreeFloor(t->left, time);
    } else {
        Time rightFloor = TreeFloor(t->right, time);
        if (rightFloor != NULL) {
            return rightFloor;
        } else {
            return t->time;
        }
    }
}