// NOTE: CHANGED TO THE STRUCUTRES INTO MACROS AS STRUCTURES IS COMPILER DEPENDENT {PADDING/ALIGNMENT}

#ifndef __FAT16_H
#define __FAT16_H

#define FAT16_BUFFER_SIZE 32
#define FAT16_BOOT_OFFSET 0X0B
#define FAT16_SECTOR_SIZE   512
#define FAT16_MEMORY_POINTER_OFFSET 0x09
#define FAT16_CLUSTER_POINTER_OFFSET_FROM_MEMORY_POINTER 16

// pointer to the first 2 bytes of the buffer
#define FAT16_ushort ((uint16_t *)((void *)fat16_buffer))

/* ******************************************** MBR ******************************************** */
/* OBSELETE
 * 
// Partition information, starts at offset 0x1BE
typedef struct {
    uint8_t first_byte;
    uint8_t start_chs[3];
    uint8_t partition_type;
    uint8_t end_chs[3];
    uint32_t start_sector;
    uint32_t length_sectors;
} __attribute__((packed)) PartitionTable;
*/

#define FAT16_MBR_SIZE  ((MBR_END_OFFSET) - (MBR_FIRST_BYTE_OFFSET))

#define MBR_FIRST_BYTE_OFFSET           0X000
#define MBR_START_CHS_OFFSET            0X001
#define MBR_PARTITION_TYPE_OFFSET       0X004
#define MBR_END_CHS_OFFSET              0X005
#define MBR_START_SECTOR_OFFSET         0X008
#define MBR_LENGTH_SECTORS_OFFSET       0X00C
#define MBR_END_OFFSET                  0X010

// NOTE: SOME ELEMENTS ARE POINTERS AND NOT VALUES, SO CARE MUST BE TAKEN WHEN USING SUCH ITEMS

#define MBR_FIRST_BYTE                  (*(uint8_t *)((void *)(fat16_buffer+MBR_FIRST_BYTE_OFFSET)))
// pointer, so when you can use it to access the first byte and increment it to access the next 2 bytes
#define MBR_START_CHS                   ((uint8_t *)((void *)(fat16_buffer+MBR_START_CHS_OFFSET)))
#define MBR_PARTITION_TYPE              (*(uint8_t *)((void *)(fat16_buffer+MBR_PARTITION_TYPE_OFFSET)))
// pointer, so when you can use it to access the first byte and increment it to access the next 2 bytes
#define MBR_END_CHS                     ((uint8_t *)((void *)(fat16_buffer+MBR_END_CHS_OFFSET)))
#define MBR_START_SECTOR                (*(uint32_t *)((void *)(fat16_buffer+MBR_START_SECTOR_OFFSET)))
#define MBR_LENGTH_SECTORS              (*(uint32_t *)((void *)(fat16_buffer+MBR_LENGTH_SECTORS_OFFSET)))
/* ******************************************** MBR ******************************************** */
// -------------------------------------------------------------------------------------------------------------
/* ******************************************** BS ********************************************* */
/* OBSELETE
 * 
// Partial FAT16 boot sector structure - non-essentials commented out
typedef struct {
    //uint8_t jmp[3];
    //int8_t oem[8];
    uint16_t sector_size;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t number_of_fats;
    uint16_t root_dir_entries;
    uint16_t total_sectors_short; // if zero, later field is used
    uint8_t media_descriptor;
    uint16_t fat_size_sectors;
    //uint16_t sectors_per_track;
    //uint16_t number_of_heads;
    //uint32_t hidden_sectors;
    //uint32_t total_sectors_long;
    //uint8_t drive_number;
    //uint8_t current_head;
    //uint8_t boot_signature;
    //uint32_t volume_id;
    //int8_t volume_label[11];
    //int8_t fs_type[8];
    //int8_t boot_code[448];
    //uint16_t boot_sector_signature;
} __attribute__((packed)) Fat16BootSectorFragment;
*/

#define FAT16_BOOT_SECTOR_SIZE  ((BS_END_OFFSET) - (BS_SECTOR_SIZE_OFFSET))

#define BS_SECTOR_SIZE_OFFSET               0X000
#define BS_SECTORS_PER_CLUSTER_OFFSET       0X002
#define BS_RESERVED_SECTORS_OFFSET          0X003
#define BS_NUMBER_OF_FATS_OFFSET            0X005
#define BS_ROOT_DIR_ENTRIES_OFFSET          0X006
#define BS_TOTAL_SECTORS_SHORT_OFFSET       0X008
#define BS_MEDIA_DESCRIPTOR_OFFSET          0X00a
#define BS_NUMBER_SECTORS_PER_FAT_OFFSET    0X00b
#define BS_SECTORS_PER_TRACK_OFFSET         0X00d
#define BS_HIDDEN_SECTORS_OFFSET            0X011
#define BS_SECTORS_ON_PARTITION_OFFSET      0X015
#define BS_END_OFFSET                       0X019

#define BS_SECTOR_SIZE                  (*(uint16_t *)((void *)(fat16_buffer+BS_SECTOR_SIZE_OFFSET)))
#define BS_SECTORS_PER_CLUSTER           (*(uint8_t *)((void *)(fat16_buffer+BS_SECTORS_PER_CLUSTER_OFFSET)))
#define BS_RESERVED_SECTORS             (*(uint16_t *)((void *)(fat16_buffer+BS_RESERVED_SECTORS_OFFSET)))
#define BS_NUMBER_OF_FATS               (*(uint8_t *)((void *)(fat16_buffer+BS_NUMBER_OF_FATS_OFFSET)))
#define BS_ROOT_DIR_ENTRIES             (*(uint16_t *)((void *)(fat16_buffer+BS_ROOT_DIR_ENTRIES_OFFSET)))
#define BS_TOTAL_SECTORS_SHORT          (*(uint16_t *)((void *)(fat16_buffer+BS_TOTAL_SECTORS_SHORT_OFFSET)))
#define BS_MEDIA_DESCRIPTOR             (*(uint8_t *)((void *)(fat16_buffer+BS_MEDIA_DESCRIPTOR_OFFSET)))
#define BS_NUMBER_SECTORS_PER_FAT       (*(uint16_t *)((void *)(fat16_buffer+BS_NUMBER_SECTORS_PER_FAT_OFFSET)))

#define BS_HIDDEN_SECTORS               (*(uint32_t *)((void *)(fat16_buffer+BS_HIDDEN_SECTORS_OFFSET)))
#define BS_SECTORS_ON_PARTITION         (*(uint32_t *)((void *)(fat16_buffer+BS_SECTORS_ON_PARTITION_OFFSET)))
/* ******************************************** BS ******************************************** */
// ------------------------------------------------------------------------------------------------------------
/* ******************************************** FE ******************************************** */
// FAT16 file entry

/* OBSELETE
 * 
typedef struct {
    uint8_t filename[8];
    uint8_t ext[3];
    uint8_t attributes;
    uint8_t reserved[10];
    uint16_t modify_time;
    uint16_t modify_date;
    uint16_t starting_cluster;
    uint32_t file_size;
} __attribute__((packed)) Fat16Entry;
*/

#define FAT16_FE_SIZE  ((FE_END_OFFSET) - (FE_FILE_NAME_OFFSET))

#define FE_FILE_NAME_OFFSET             0X000
#define FE_EXT_OFFSET                   0X008
#define FE_ATTRIBUTES_OFFSET            0X00b
#define FE_RESERVED_OFFSET              0X00c
#define FE_MODIFY_TIME_OFFSET           0X016
#define FE_MODIFY_DATE_OFFSET           0X018
#define FE_STARTING_CLUSTER_OFFSET      0X01a
#define FE_FILE_SIZE_OFFSET             0X01c
#define FE_END_OFFSET                   0X020

// NOTE: SOME ELEMENTS ARE POINTERS AND NOT VALUES, SO CARE MUST BE TAKEN WHEN USING SUCH ITEMS

// pointer, so we can use it to access the next bytes in the same item
#define FE_FILE_NAME                    ((uint8_t *)((void *)(fat16_buffer+FE_FILE_NAME_OFFSET)))
// pointer, so when you can use it to access the first byte and increment it to access the next bytes
#define FE_EXT                          ((uint8_t *)((void *)(fat16_buffer+FE_EXT_OFFSET)))
#define FE_ATTRIBUTES                   (*(uint8_t *)((void *)(fat16_buffer+FE_ATTRIBUTES_OFFSET)))
// pointer, so when you can use it to access the first byte and increment it to access the next bytes
#define FE_RESERVED                     ((uint8_t *)((void *)(fat16_buffer+FE_RESERVED_OFFSET)))
#define FE_MODIFY_TIME                  (*(uint16_t *)((void *)(fat16_buffer+FE_MODIFY_TIME_OFFSET)))
#define FE_MODIFY_DATE                  (*(uint16_t *)((void *)(fat16_buffer+FE_MODIFY_DATE_OFFSET)))
#define FE_STARTING_CLUSTER             (*(uint16_t *)((void *)(fat16_buffer+FE_STARTING_CLUSTER_OFFSET)))
#define FE_FILE_SIZE                    (*(uint32_t *)((void *)(fat16_buffer+FE_FILE_SIZE_OFFSET)))
/* ******************************************** FE ******************************************** */
// ------------------------------------------------------------------------------------------------------------

// State data required by FAT16 library
typedef struct {
   uint32_t fat_start; // FAT start position
   uint32_t root_start; // root directory position
   uint32_t data_start; // data start position
   uint8_t sectors_per_cluster; // cluster size in sectors
   uint16_t cluster; // current cluster being read
   uint32_t cluster_left; // bytes left in current cluster
   uint32_t file_left; // bytes left in the file being read
   uint32_t data_sectors;   // no. of sectors in the data area
   uint32_t data_clusters;  // no. of clusters in the data area
} __attribute__((packed)) Fat16State;

// Global variables for read data and library state
extern uint8_t fat16_buffer[FAT16_BUFFER_SIZE];
extern Fat16State fat16_state;

/* OBSELETE  *****************************************************************
 * 
// Aliases for fat16_buffer in different formats
//#define FAT16_part ((PartitionTable *)((void *)fat16_buffer))
//#define FAT16_boot ((Fat16BootSectorFragment *)((void *)fat16_buffer))
//#define FAT16_entry ((Fat16Entry *)((void *)fat16_buffer))
**************************************************************************** */


/* *************************************** H/W DEPENDENT FUNCTIONS *************************************** */
// The following functions need to be provided for the library

// Go to specified offset. Next FAT16_read should continue from here
void FAT16_seek(uint32_t offset);
// Read <bytes> to fat16_buffer, and return the amount of bytes read
int8_t FAT16_read(uint8_t *ptr, uint8_t bytes);
// Write <bytes> to fat16_buffer, and returns nothing
int8_t FAT16_write(uint8_t bytes);
/* ********************************************************************************************************* */


/* *************************************** H/W INDEPENDENT FUNCTIONS *************************************** */
// The following functions are provided by the library

// Error codes for FAT16_init()
#define FAT16_ERR_NO_PARTITION_FOUND -1
#define FAT16_ERR_INVALID_SECTOR_SIZE -2

// Initialize the FAT16 library. Nonzero return value indicates
// an error state. After init, the file stream is pointed to
// the beginning of root directory entry.
int8_t FAT16_init(void); // nonzero return values indicate error state

// Error codes for FAT16_open_file()
#define FAT16_ERR_FILE_NOT_FOUND -1
#define FAT16_ERR_FILE_READ -2

// Open a given file. Assumes that the stream is currently at
// a directory entry and fat16_state.file_left contains the
// amount of file entries available. Both conditions are satisfied
// after FAT16_init(), and also after opening a directory with this.
int8_t FAT16_open_file(int8_t *filename, int8_t *ext);

// Read <bytes> from file. Returns the bytes actually read, and
// 0 if end of file is reached. This method will automatically
// traverse all clusters of a file using the file allocation table
int8_t FAT16_read_file(int8_t bytes);

// Error codes for FAT16_create_file()
#define FAT16_FILE_EXIST 1
#define FAT16_ERR_FILE_CREATE -2
// Position Offset Used When Creating the File
#define FAT16_CREATE_FILE_ROOT_OFFSET   64

#define FAT16_FILE_SIZE_ENTRY_OFFSET    92
#define FAT16_FILE_CURRENT_CLUSTER_OFFSET 90

// creates a new file with <bytes> size. then goes to the first cluster of the file.
// the created file only occupies one cluster.
// returns 0 for successful file creation
// returns 1 if the file already exists
// return -2 if the file creation isn't successful (maybe due to formating fault)
int8_t FAT16_create_file(int8_t *filename, int8_t *ext);

// Error codes for FAT16_write_file()
#define FAT16_END_OF_FILE -1

// writes to a file "specified by filename". returns 0 at success, non-zero at failure.
int8_t FAT16_write_file(int8_t bytes);
/* ********************************************************************************************************* */


/* ****************************************** UTILITIES FUNCTIONS ****************************************** */
int strlen(char *s);
void reverse(char *str);
uint8_t itoa(uint32_t n, uint8_t s[]);
/* ********************************************************************************************************* */

#endif
