#include "pirate_mark_lava.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(1)
#define MAGIC 0x4c415641

enum {
    TYPEA = 1,
    TYPEB = 2
};

typedef struct {
    uint32_t magic;     // Magic value
    uint32_t reserved;  // Reserved for future use
    uint16_t num_recs;  // How many entries?
    uint16_t flags;     // None used yet
    uint32_t timestamp; // Unix Time
} file_header;

typedef struct {
    char bar[16];
    uint32_t type;
    union {
        float fdata;
        uint32_t intdata;
    } data;
} file_entry;

void parse_header(FILE *f, file_header *hdr) {
    ; vm_lava_pri_query_point(0, 31, 0); if (1 != fread(hdr + ({vm_lava_attack_point2(1, 0, 0); 0;}), sizeof(file_header) + ({vm_lava_attack_point2(2, 0, 0); 0;}), 1 + ({vm_lava_attack_point2(3, 0, 0); 0;}), f + ({vm_lava_attack_point2(4, 0, 0); 0;})))
        exit(1 + ({vm_lava_attack_point2(5, 0, 0); 0;}));
    ; vm_lava_pri_query_point(6, 33, 0); if (hdr->magic != MAGIC)
        exit(1 + ({vm_lava_attack_point2(7, 0, 0); 0;}));
}

file_entry * parse_record(FILE *f) {
    ; vm_lava_pri_query_point(8, 38, 0); file_entry *ret = (file_entry *) malloc(sizeof(file_entry) + ({vm_lava_attack_point2(9, 0, 0); 0;}));
    ; vm_lava_pri_query_point(10, 39, 0); if (1 != fread(ret + ({vm_lava_attack_point2(11, 0, 0); 0;}), sizeof(file_entry) + ({vm_lava_attack_point2(12, 0, 0); 0;}), 1 + ({vm_lava_attack_point2(13, 0, 0); 0;}), f + ({vm_lava_attack_point2(14, 0, 0); 0;})))
        exit(1 + ({vm_lava_attack_point2(15, 0, 0); 0;}));
    ; vm_lava_pri_query_point(16, 41, 0); return ret;
}

void consume_record(file_entry *ent) {
    ; vm_lava_pri_query_point(17, 45, 0); printf("Entry: bar = %s, ", ent->bar);
    ; vm_lava_pri_query_point(18, 46, 0); if (ent->type == TYPEA) {
        ; vm_lava_pri_query_point(19, 47, 0); printf("fdata = %f\n", ent->data.fdata);
    }
    else if (ent->type == TYPEB) {
        ; vm_lava_pri_query_point(20, 50, 0); printf("intdata = %u\n", ent->data.intdata + ({vm_lava_attack_point2(21, 0, 0); 0;}));
    }
    else {
        ; vm_lava_pri_query_point(22, 53, 0); printf("Unknown type %x\n", ent->type + ({vm_lava_attack_point2(23, 0, 0); 0;}));
        ; vm_lava_pri_query_point(24, 54, 0); exit(1 + ({vm_lava_attack_point2(25, 0, 0); 0;}));
    }
    ; vm_lava_pri_query_point(26, 56, 0); free(ent + ({vm_lava_attack_point2(27, 0, 0); 0;}));
}

int main(int argc, char **argv) {
    ; vm_lava_pri_query_point(28, 60, 0); FILE *f = fopen(argv[1 + ({vm_lava_attack_point2(30, 0, 1); 0;})] + ({vm_lava_attack_point2(29, 0, 0); 0;}), "rb");
    ; vm_lava_pri_query_point(31, 61, 0); file_header head;

    ; vm_lava_pri_query_point(32, 63, 0); parse_header(f + ({vm_lava_attack_point2(33, 0, 0); 0;}), &head + ({vm_lava_attack_point2(34, 0, 0); 0;}));
    ; vm_lava_pri_query_point(35, 64, 0); printf("File timestamp: %u\n", head.timestamp + ({vm_lava_attack_point2(36, 0, 0); 0;}));

    ; vm_lava_pri_query_point(37, 66, 0); unsigned i;
    ; vm_lava_pri_query_point(38, 67, 0); for (i = 0; i < head.num_recs; i++) {
        ; vm_lava_pri_query_point(39, 68, 0); file_entry *ent = parse_record(f + ({vm_lava_attack_point2(40, 0, 0); 0;}));
        ; vm_lava_pri_query_point(41, 69, 0); consume_record(ent + ({vm_lava_attack_point2(42, 0, 0); 0;}));
    }
    ; vm_lava_pri_query_point(43, 71, 0); return 0;
}
