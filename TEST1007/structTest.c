#include </afs/cs.pitt.edu/usr0/jih127/private/TomasuloSimulator/OurForm.h>

//int getHashCode(void* key);
//int compareValues(void* value1, void* value2);

int getHashCode(int* key){

	return *key;
}

int compareValues(void* value1, void* value2){
	if(value1 == value2){
		return 0;
	}
	else{
		return 1;
	}
}

static inline RSRow* createRSRow(int Key){
	RSRow* res = (RSRow*)malloc(sizeof(RSRow));
	res->Key = &Key;
	res->name = "N";
//	res->op = "NOOP";
	res->busy = 0;

//	res->intVjRR = -1;
//	res->intVkRR = -1;
//	res->fpVjRR = -1;
//	res->fpVkRR = -1;
	res->Qj = NULL;
	res->Qk = NULL;
	res->dest = NULL;
	res->A = NULL;
	
}

void mainROB(){
	CircularQueue *ROB;
	int UpperSizeOfROB = 4;
	int OperNumth = 2;
	ROB = createCircularQueue(UpperSizeOfROB); //create size = UpperSizeROB CircularQueue
	robRow *rRow2;
	robRow *rRow0 = malloc (sizeof(robRow));
	robRow *rRow1 = malloc (sizeof(robRow)); 
	rRow2 = malloc (sizeof(robRow)); 
	robRow *rRow3 = malloc (sizeof(robRow));
	robRow *rRowOper = malloc (sizeof(robRow));
	printf("The entry number of the %d is %d\n ", OperNumth, rRow2->Key);
	enqueueCircular(ROB, rRow0);
	enqueueCircular(ROB, rRow1);
	enqueueCircular(ROB, rRow2);
	enqueueCircular(ROB, rRow3);
	
	rRowOper = getNumthCircularQueue(ROB, OperNumth); //return a pointer which is the OperNumth Row in ROB
	rRowOper->Key = OperNumth;
	printf("After revision, the entry number of the %d is %d\n ", OperNumth, rRow2->Key);
 	
	printf("Test result is:\n");
	printf("%d\n", getCountCircularQueue(ROB));
}

void main(){
	RSRow* rsRow0 = createRSRow(0);
	RSRow* rsRow1 = createRSRow(1);
	RSRow* rsRow2 = createRSRow(2);
	RSRow* rsRow3 = createRSRow(3);
	RSRow* rsRow4 = createRSRow(4);
	RSRow* Oper_rsRow;
	Dictionary* RS = createDictionary(getHashCode, compareValues);
	DictionaryEntry* rsEntry0 = createDictionaryEntry(RS, rsRow0->Key, rsRow0);
	DictionaryEntry* rsEntry1 = createDictionaryEntry(RS, rsRow1->Key, rsRow1);
	DictionaryEntry* rsEntry2 = createDictionaryEntry(RS, rsRow2->Key, rsRow2);
	DictionaryEntry* rsEntry3 = createDictionaryEntry(RS, rsRow3->Key, rsRow3);
	DictionaryEntry* rsEntry4 = createDictionaryEntry(RS, rsRow4->Key, rsRow4);

	//return the rsRow with its responding key
	Oper_rsRow = getValueChainByDictionaryKey(RS, rsRow0->Key);
	Oper_rsRow->busy = 1;
	Oper_rsRow->Qj = 100;
	printf("busy is %d, and Qj is %s", Oper_rsRow->busy, Oper_rsRow->Qj);
}
