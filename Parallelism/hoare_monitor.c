Monitor ReaderWriter {
    void BeginRead();
    void EndRead();
    void BeginWrite();
    void EndWrite()
    Condition WCond, RCond;
    // State variables
    int nbReaders = 0;
    bool activeWriter = false;
} end ReaderWriter

void BeginRead() {
    if(activeWriter == true) {
        RCond.wait();
    }
    nbReaders++;
} end BeginRead

void EndRead() {
    nbReaders--;
    if(nbReaders == 0) {
        WCond.signal();
    }
} end EndRead

void BeginWrite() {
    if(activeWriter == true || nbReaders != 0) {
        WCond.wait();
    }
    activeWriter = true;
} end BeginWrite

void EndWrite() {
    activeWriter = false;
    if(RCond.size() > 0) {
        for(i = 0; i < RCond.size(); i++) {
            RCond.signal();
        }
    } else {
        WCond.signal();
    }
} end EndWrite


// version4:
BeginRead {
    if(activeReaders) {
        cond.wait(0);
    }
    nbReaders++;
    cond.signal();
}

BeginWrite {
   if(activeWriter || nbReaders > 0) {
       cond.wait(0);
   } 
   activeWriter = true;
}

EndRead {
    nbReaders--;
    if(nbReaders == 0) {
        cond.signal();
    }
}

EndWrite {
    activeWriter = false;
    cond.signal();
}