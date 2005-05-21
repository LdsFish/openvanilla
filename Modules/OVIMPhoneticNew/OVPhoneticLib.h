// OVPhoneticLib.h

#ifndef __OVPhoneticLib_h
#define __OVPhoneticLib_h

enum {
    OVPStandardLayout=0,
    OVPEtenLayout=1
};

class OVPCandidate;

class OVPhoneticSyllable
{
public:
    OVPhoneticSyllable(int layout=OVPStandardLayout);
    
    int layout();
    void setLayout(int layout);
    
    int empty();
    int isComposeKey(char c);
    int addKey(char c);
    int isValidKey(char c);
    int removeLast();
    void clear();
    
    const char *compose();
    const char *standardLayoutCode();
    
protected:
    unsigned short syllable;
    int keylayout;
    friend OVPCandidate* OVPFindCandidate(unsigned short *data, OVPhoneticSyllable *s);
};

struct OVPCandidate
{
    OVPCandidate();
    ~OVPCandidate();
    int count;
    char **candidates;
};

// you're responsible to delete the object returned
OVPCandidate *OVPFindCandidate(unsigned short *data, OVPhoneticSyllable *syl);

#endif

