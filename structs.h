#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_DUPLICATE_KEY,
} ExecuteResult;

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
} MetaCommandResult;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareResult;

typedef enum {
    STATEMENT_INSERT, 
    STATEMENT_SELECT,
    STATEMENT_UPDATE,
    STATEMENT_DELETE,
} StatementType;

typedef enum {
    COLUMN_INT,
    COLUMN_TEXT,
    COLUMN_BIN,
} ColumnType;

typedef struct {
    char* name;
    ColumnType type;
    size_t size;
} Column;

typedef struct {
    size_t column_count;
    Column* columns;
} TableSchema;

typedef struct {
    TableSchema* schema;
    void** values;
} Row;

typedef struct {
    StatementType type;
    Row row;
} Statement;
