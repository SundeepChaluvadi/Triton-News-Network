// --------------------------------------------------------------------------
//
// Project P2
// Sundeep Chaluvadi
//
// CS5130 Advanced Algorithms
//
// Sharlee Climer, August 2023
//
// --------------------------------------------------------------------------

#include "P2.h"

int get_combinations(){
    int combinations = 1;
    for(int i = 1;i <= numArticles;i++)
        combinations *= 2;
    return combinations;
}

int compareArticles(const void *a, const void *b) {
    struct Article *structA = (struct Article *)a;
    struct Article *structB = (struct Article *)b;
    
    if (structA->cost < structB->cost) return -1;
    if (structA->cost > structB->cost) return 1;
    return 0;
}

int getUniqueArray(int originalArray[],int uniqueArray[], int n){


    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        int isUnique = 1;

        for (int j = 0; j < uniqueCount; j++) {
            if (originalArray[i] == uniqueArray[j]) {
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            uniqueArray[uniqueCount] = originalArray[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
    
}

void decimalToBinary(int** arr, int decimalNumber, int numPlaces) {
    int binary[numPlaces];
    for (int i = 0; i < numPlaces; i++) {
        binary[i] = decimalNumber & 1;
        decimalNumber >>= 1;
    }
    
    for(int i = 0;i < numPlaces;i++){
        if(binary[i] == 1){
            count++;
        }
    }
    
    if(count >= combinationCount){
        for (int i = numPlaces - 1; i >= 0; i--) {
            arr[ctr][i] = binary[i];
        }
    }
    
}

int isValueInArray(int value, int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1; 
        }
    }
    return 0;
}

int initialCost (int** arr,int c){
    
    int totalCost = 0;
    for(int i = 0;i < numArticles;i++){
        if(arr[c][i] == 1){
            totalCost += articles[i].cost;
        }       
    }
    
    return totalCost;

}

bool constraint_4(int** arr,int c){

    bool Constraint;
    bool gFlag = false;
    bool sFlag = false;
    bool eFlag = false;
    bool lFlag = false; 
    
    for(int i = 0;i < numArticles;i++){
        if(arr[c][i] == 1){            
            if(articles[i].type == 'G')
                gFlag = true;
            else if(articles[i].type == 'S')
                sFlag = true;
            else if(articles[i].type == 'E')
                eFlag = true;
            else if(articles[i].type == 'L')
                lFlag = true;  
        }
    }

    Constraint = gFlag && sFlag && eFlag && lFlag;
    
    return Constraint;
}

bool constraint_5(int** arr,int c){

    int gCtr=0, sCtr=0, eCtr=0, lCtr=0;
    bool Constraint5;   
    int num = numArticles/2;
    
    for(int i = 0;i < numArticles;i++){
        if(arr[c][i] == 1)
            if(articles[i].type == 'G')
                gCtr++;
            else if(articles[i].type == 'S')
                sCtr++;
            else if(articles[i].type == 'E')
                eCtr++;
            else if(articles[i].type == 'L') 
                lCtr++;
    }

    if(gCtr > num || sCtr > num || eCtr > num || lCtr > num)
        Constraint5 = false;
    else
        Constraint5 = true;
        
    return Constraint5;

}

int getClicks(int** arr,int c,int Tclicks){
    
    for(int i = 0;i < numArticles;i++){
        if(arr[c][i] == 1){
            Tclicks += articles[i].clicks;
        }
    }
    
    return Tclicks;
}

bool constraint_3(int** arr,int totalClicks){
  
    bool Constraint3;
    
    if(totalClicks >= requiredClicks)
        Constraint3 = true;
    else
        Constraint3 = false;
        
    return Constraint3;

}

int constraint_6(int** arr,int c){
    
    int Constraint6 = 0; 
    
    for(int i = 0;i < 256;i++)
        articleCount[i] = 0;
    
    for(int i = 0;i < numArticles;i++){
        if(arr[c][i] == 1){
            articleCount[articles[i].type - 'A']++;
        }
    }
    
    if(articleCount['G' - 'A'] >= 2)
        Constraint6 += 150;
    if(articleCount['E' - 'A'] >= 2)
        Constraint6 += 150;
    if(articleCount['S' - 'A'] >= 2)
        Constraint6 += 150;
    if(articleCount['L' - 'A'] >= 2)
        Constraint6 += 150;

    Constraint6 = Constraint6*(-1);
    
    return Constraint6;
}

bool constraint_1(int** arr,int c){
  
    bool Constraint1 = true;
    
    for(int i = 0;i < 256;i++)
        articleCount[i] = 0;

    for(int i = 0; i < numArticles;i++){
        if(arr[c][i] == 1)
            articleCount[articles[i].reporter]++;
    }

    for(int i = 0;i < numArticles;i++){
        if(articleCount[articles[i].reporter] < 1){
            Constraint1 = false;
        }        
    }
    
    return Constraint1;
}

int constraint_2(int** arr,int c){
    int total=0, Constraint2 = 0; 
    for(int i = 0;i < 256;i++)
        articleCount[i] = 0;

    for(int i = 0;i < numArticles;i++){
        if(arr[c][i] == 1){
            articleCount[articles[i].reporter]++;
        }
    }

    int originalArray[numArticles];
    for(int i = 0;i < numArticles;i++)
        originalArray[i] = 0;
    for(int i = 0; i < numArticles;i++)
        if(arr[c][i] == 1)
            originalArray[i] = articles[i].reporter;

    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);
    int uniqueArray[originalSize];
    int uniqueSize = 0;

    for (int i = 0; i < originalSize; i++) {
        int currentValue = originalArray[i];

        if (!isValueInArray(currentValue, uniqueArray, uniqueSize)) {
            uniqueArray[uniqueSize] = currentValue;
            uniqueSize++;
        }
    }

    for(int i = 0;i < uniqueSize;i++){
        if(articleCount[uniqueArray[i]] > 1){
            total += (articleCount[uniqueArray[i]] - 1);
        }
        
    }
    Constraint2 = total*100;
    return Constraint2;
}


void checkConstraints(int** arr,int** output,int c){    
        
    totalCost = initialCost(arr, c);
    
    bool Constraint1 = constraint_1(arr, c);
    
    int Constraint2 = constraint_2(arr, c);
    
    int totalClicks = getClicks(arr, c, 0);  
    bool Constraint3 = constraint_3(arr, totalClicks);
     
    bool Constraint4 = constraint_4(arr, c);    
            
    bool Constraint5 = constraint_5(arr, c);   
     
    int Constraint6 = constraint_6(arr, c);
    
    bool validCombination;
     
    validCombination = Constraint4 && Constraint5 && Constraint3 && Constraint1;
    totalCost += Constraint2;
    totalCost += Constraint6;    

    if(validCombination == true){        
        if(totalCost < minimumCost){
            
            minimumCost = totalCost;
            
            for(int i = 0;i < numArticles;i++){
                output[0][i] = arr[c][i];
            }

            outputClicks = totalClicks;
        }
        else{
            return;        
        }
    }
    else{
        return;    
    }      
}


int main(int argc, char ** argv) {

    if (argc != 2){
        printf("Usage:\n\n   P0 inputFileName  (input file contains a list of names\n\n");
        return 0;
    }
    
    timer t;
    t.start("Timer started.");

    char *inputFileName = argv[1];  
    FILE *inputFile;
    char tempStrng [1000];
    
    if (!QUIET) {
        std::cout << "\nCommand line arguments: \n\t";
        for (int i = 0; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << "\n\n";
        std::cout << "Input will be read from '" << inputFileName << "'.\n";
    }

    if ((inputFile = fopen(inputFileName, "r")) == NULL){
        fatal("Unable to open input file.");
        return 0;
    }
    
    fscanf(inputFile, "%d articles and %d reporters", &numArticles, &numReporters);
    fscanf(inputFile, "%d clicks or more required", &requiredClicks);

    fscanf(inputFile, "%*s %*s %*s %*s %*s");
    
    for (int i = 0; i < numArticles; i++) {
        fscanf(inputFile, "%s %c %d %d %d", &articles[i].name, &articles[i].type, &articles[i].reporter, &articles[i].cost, &articles[i].clicks);
    }
    fclose(inputFile);
    
    qsort(articles, numArticles, sizeof(struct Article), compareArticles);

    
    bool typeFlag = false;
    bool reporterFlag = false;
    for (int i = 0; i < numArticles-1; i++) {
        if(articles[numArticles-1].type == articles[i].type){
            typeFlag = true;
        }
        
        if(articles[numArticles-1].reporter == articles[i].reporter){
            reporterFlag = true;        
        }
    }
    
    if(typeFlag == true && reporterFlag == true){
        numArticles--;   
    }
    
    
    int noOfCombinations = get_combinations();
    
    int originalArray[numArticles], uniqueArray[numArticles];
    for(int i = 0;i < numArticles;i++){
        originalArray[i] = articles[i].reporter;    
    }
    
    combinationCount = getUniqueArray(originalArray, uniqueArray, numArticles);
    
    if(combinationCount < 4){
      combinationCount = 4;    
    }
    
    if(combinationCount < numArticles){
        noOfCombinations--;    
    }
    
    int** output = (int**)malloc(1 * sizeof(int*));
    for (int i = 0; i < 1; i++) {
        output[i] = (int*)malloc(numArticles * sizeof(int));
        
    }       

    int** arr = (int**)malloc(noOfCombinations * sizeof(int*));
    for (int i = 0; i < noOfCombinations; i++) {
        arr[i] = (int*)malloc(numArticles * sizeof(int));
        decimalToBinary(arr,i, numArticles);
        ctr++;
        
        if(count < combinationCount){
            count = 0;
            free(arr[i]);
            continue;
        }
        
        checkConstraints(arr,output,i);
        free(arr[i]);
        count = 0;
    }    
        
    t.stop("\nTimer stopped.");
    double compTime;
    compTime = t.timeVal();
  
    int seconds = 0;
    int min = 0;
    int hour = 0;
  
    seconds = (int)compTime % 60;
    min = (int)compTime / 60;
    hour = min / 60;
    min = min % 60;      
   
    for (int i = 0; i < STRING_LENGTH; i++) {
        base[i] = inputFileName[i]; 
        if (base[i] == '\0') {
	        if(i < 5)
	            fatal("Expected output file name to have at least 5 characters");
	
            base[i-4] = '\0';  
            break;
            }
    } 
    sprintf(outputFileName, "%s%s", base, outSuffix); 
    
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fatal("Failed to create the output file.\n");
        return 1;
    }

    fprintf(outputFile, "Article\t         Type\t      Reporter\t       Cost\t       Clicks\n");
    for (int i = 0; i < numArticles; i++) {
        if(output[0][i] == 1){
            fprintf(outputFile, "%s\t\t   %c\t\t%d\t\t%d\t\t%d\n", articles[i].name, articles[i].type, articles[i].reporter, articles[i].cost, articles[i].clicks);
        }
    }

    fprintf(outputFile, "Total Cost: %d\n", minimumCost);
    fprintf(outputFile, "Total Clicks: %d\n", outputClicks);
    if (!QUIET)
        fprintf(outputFile, "Computation Time: %d hours, %d minutes, %d seconds.\n", hour, min, seconds);

    fclose(outputFile);

    printf("\nOutput file %s%s created.\n\n", base, outSuffix);

    return 0;
}