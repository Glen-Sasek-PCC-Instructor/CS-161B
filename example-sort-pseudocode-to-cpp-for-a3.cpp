// ----- PSEUDOCODE FROM A3 INSTRUCTIONS -----
// procedure selection sort
//   list  : array of items
//   count : size of list
//   for i = 0 to count - 1
//
//     /* set current element as minimum */
//     min = i
//
//     /*go through the list and find the smallest element */
//     for j = i + 1 to count
//         if list[j] < list[min] then
//             min = j;
//         end if
//     end for
//
//     /* swap the minimum element with the current element If they are not the same element */
//     if min != i  then
//         swap list[min] and list[i]
//     end if
//   end for
// end procedure


// ----- CPP ----- 
// Start with just scores and count, next section adds grades parallel array.
//
// void sort(double scores[], int count) {
//     for (int i = 0; i < count - 1; ++i) {
//         int min = i;  // set current element as minimum
//
//         // find the smallest element in the rest of the array
//         for (int j = i + 1; j < count; ++j) {
//             if (scores[j] < scores[min]) {
//                 min = j;
//             }
//         }
//
//         // swap the found minimum with the current element
//         if (min != i) {
//             double temp = scores[i];
//             scores[i] = scores[min];
//             scores[min] = temp;
//         }
//     }
// }

// ----- CPP ----- 
void sort(double scores[], char grades[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        int min = i;  // set current element as minimum

        // find the smallest element in the rest of the array
        for (int j = i + 1; j < count; ++j) {
            if (scores[j] < scores[min]) {
                min = j;
            }
        }

        // swap the found minimum with the current element
        if (min != i) {
            double temp = scores[i];
            scores[i] = scores[min];
            scores[min] = temp;

            // Add code to update parallel grades array
            char c  = grades[i];
            grades[i] = grades[min];
            grades[min] = c;
        }
    }
}