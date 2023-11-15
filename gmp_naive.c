#include <stdint.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <immintrin.h>

#define VECT_SIZE 1000

static inline uint64_t rdtsc() {
	unsigned long a, d;
    asm volatile("rdtsc" : "=a" (a), "=d" (d));
    return a | ((uint64_t)d << 32);
}

uint32_t mult_naive(uint32_t *arrayA, uint32_t *arrayB, size_t size) {
    uint32_t result;

    for (size_t i = 0; i < VECT_SIZE; i++) {
        result += (arrayA[i] * arrayB[i]);
    }

    return result;
}

int main(void) {
    // uint32_t a[VECT_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
	// uint32_t b[VECT_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    // 9

    // uint32_t a[VECT_SIZE] = {80, 89, 43, 35, 98, 55, 21, 97, 60, 42, 42, 25, 84, 9, 85, 95};
    // uint32_t b[VECT_SIZE] = {80, 89, 43, 35, 98, 55, 21, 97, 60, 42, 42, 25, 84, 9, 85, 95};
    // 16

    // uint32_t a[VECT_SIZE] = {57, 42, 34, 25, 20, 83, 13, 61, 35, 75, 17, 91, 28, 67, 29, 55, 97, 31, 61, 36, 32, 55, 44, 93};
    // uint32_t b[VECT_SIZE] = {57, 42, 34, 25, 20, 83, 13, 61, 35, 75, 17, 91, 28, 67, 29, 55, 97, 31, 61, 36, 32, 55, 44, 93};
    // 24

    // uint32_t a[VECT_SIZE] = {64, 95, 56, 39, 22, 20, 87, 36, 76, 66, 75, 68, 28, 59, 35, 67, 13, 99, 81, 48, 81, 50, 18, 58, 18, 50, 63, 71, 9, 41, 47, 50};
    // uint32_t b[VECT_SIZE] = {64, 95, 56, 39, 22, 20, 87, 36, 76, 66, 75, 68, 28, 59, 35, 67, 13, 99, 81, 48, 81, 50, 18, 58, 18, 50, 63, 71, 9, 41, 47, 50};
    // 32

    // uint32_t a[VECT_SIZE] = {43, 51, 87, 38, 65, 43, 77, 100, 94, 12, 23, 23, 91, 72, 74, 42, 95, 77, 96, 41, 87, 98, 44, 53, 67, 99, 91, 59, 74, 69, 88, 15, 81, 37, 17, 71, 74, 55, 99, 63};
    // uint32_t b[VECT_SIZE] = {43, 51, 87, 38, 65, 43, 77, 100, 94, 12, 23, 23, 91, 72, 74, 42, 95, 77, 96, 41, 87, 98, 44, 53, 67, 99, 91, 59, 74, 69, 88, 15, 81, 37, 17, 71, 74, 55, 99, 63};
    // 40

    // uint32_t a[VECT_SIZE] = {99, 59, 91, 88, 69, 96, 17, 44, 82, 53, 54, 11, 88, 23, 83, 67, 87, 90, 74, 61, 73, 56, 74, 13, 58, 34, 10, 37, 15, 83, 9, 50, 9, 19, 59, 36, 32, 54, 44, 58, 63, 96, 78, 86, 42, 54, 45, 21};
    // uint32_t b[VECT_SIZE] = {99, 59, 91, 88, 69, 96, 17, 44, 82, 53, 54, 11, 88, 23, 83, 67, 87, 90, 74, 61, 73, 56, 74, 13, 58, 34, 10, 37, 15, 83, 9, 50, 9, 19, 59, 36, 32, 54, 44, 58, 63, 96, 78, 86, 42, 54, 45, 21};
    // 48

    // uint32_t a[VECT_SIZE] = {39, 49, 44, 71, 46, 66, 94, 32, 91, 44, 39, 47, 24, 52, 78, 77, 12, 30, 80, 49, 14, 96, 26, 45, 13, 51, 11, 85, 30, 97, 84, 69, 10, 50, 28, 16, 67, 28, 30, 93, 32, 99, 19, 50, 37, 9, 34, 14, 65, 73, 67, 25, 47, 16, 83, 9};
    // uint32_t b[VECT_SIZE] = {39, 49, 44, 71, 46, 66, 94, 32, 91, 44, 39, 47, 24, 52, 78, 77, 12, 30, 80, 49, 14, 96, 26, 45, 13, 51, 11, 85, 30, 97, 84, 69, 10, 50, 28, 16, 67, 28, 30, 93, 32, 99, 19, 50, 37, 9, 34, 14, 65, 73, 67, 25, 47, 16, 83, 9};
    // 56

    // uint32_t a[VECT_SIZE] = {55, 69, 73, 33, 92, 96, 22, 93, 39, 84, 11, 16, 13, 58, 63, 45, 91, 18, 96, 80, 95, 43, 63, 24, 56, 89, 79, 66, 80, 54, 58, 22, 69, 54, 93, 75, 52, 45, 60, 47, 18, 74, 44, 11, 10, 66, 42, 51, 87, 32, 30, 20, 47, 11, 99, 75, 92, 76, 40, 16, 60, 94, 48, 88};
    // uint32_t b[VECT_SIZE] = {55, 69, 73, 33, 92, 96, 22, 93, 39, 84, 11, 16, 13, 58, 63, 45, 91, 18, 96, 80, 95, 43, 63, 24, 56, 89, 79, 66, 80, 54, 58, 22, 69, 54, 93, 75, 52, 45, 60, 47, 18, 74, 44, 11, 10, 66, 42, 51, 87, 32, 30, 20, 47, 11, 99, 75, 92, 76, 40, 16, 60, 94, 48, 88};
    // 64

    // uint32_t a[VECT_SIZE] = {30, 59, 78, 68, 26, 50, 75, 30, 81, 61, 14, 34, 80, 13, 85, 82, 38, 28, 36, 46, 27, 62, 70, 81, 98, 91, 54, 68, 86, 93, 98, 21, 26, 93, 45, 27, 47, 32, 69, 12, 12, 21, 18, 20, 23, 83, 12, 42, 42, 61, 95, 98, 17, 23, 83, 38, 98, 36, 35, 17, 83, 77, 68, 29, 32, 45, 90, 84, 12, 87, 82, 40};
    // uint32_t b[VECT_SIZE] = {30, 59, 78, 68, 26, 50, 75, 30, 81, 61, 14, 34, 80, 13, 85, 82, 38, 28, 36, 46, 27, 62, 70, 81, 98, 91, 54, 68, 86, 93, 98, 21, 26, 93, 45, 27, 47, 32, 69, 12, 12, 21, 18, 20, 23, 83, 12, 42, 42, 61, 95, 98, 17, 23, 83, 38, 98, 36, 35, 17, 83, 77, 68, 29, 32, 45, 90, 84, 12, 87, 82, 40};
    // 72

    // uint32_t a[VECT_SIZE] = {96, 66, 75, 74, 65, 61, 82, 38, 16, 38, 60, 42, 67, 60, 80, 53, 72, 74, 59, 12, 99, 86, 31, 46, 54, 32, 90, 13, 97, 11, 65, 77, 25, 22, 62, 94, 22, 57, 90, 76, 48, 64, 77, 53, 28, 92, 63, 95, 90, 35, 47, 38, 91, 98, 93, 38, 72, 45, 69, 30, 13, 14, 61, 44, 24, 17, 55, 63, 39, 52, 86, 61, 47, 14, 62, 19, 71, 54, 70, 87};
    // uint32_t b[VECT_SIZE] = {96, 66, 75, 74, 65, 61, 82, 38, 16, 38, 60, 42, 67, 60, 80, 53, 72, 74, 59, 12, 99, 86, 31, 46, 54, 32, 90, 13, 97, 11, 65, 77, 25, 22, 62, 94, 22, 57, 90, 76, 48, 64, 77, 53, 28, 92, 63, 95, 90, 35, 47, 38, 91, 98, 93, 38, 72, 45, 69, 30, 13, 14, 61, 44, 24, 17, 55, 63, 39, 52, 86, 61, 47, 14, 62, 19, 71, 54, 70, 87};
    // 80

    uint32_t a[VECT_SIZE] = {163, 214, 424, 553, 355, 142, 476, 128, 318, 331, 753, 338, 322, 321, 737, 267, 253, 72, 91, 671, 790, 607, 420, 692, 658, 143, 783, 776, 16, 784, 269, 366, 321, 639, 706, 22, 232, 743, 470, 518, 291, 665, 409, 771, 724, 330, 177, 529, 439, 297, 456, 29, 443, 390, 338, 647, 390, 93, 799, 724, 247, 233, 614, 284, 691, 254, 412, 529, 800, 91, 307, 15, 706, 107, 597, 127, 400, 479, 78, 742, 760, 656, 199, 539, 776, 79, 485, 223, 185, 217, 263, 368, 626, 714, 330, 556, 716, 378, 280, 657, 541, 40, 77, 36, 688, 719, 335, 626, 50, 228, 793, 480, 302, 657, 532, 311, 703, 31, 409, 66, 602, 486, 11, 505, 608, 189, 13, 517, 401, 521, 750, 416, 622, 213, 95, 719, 540, 393, 491, 237, 169, 616, 482, 36, 460, 107, 586, 770, 535, 190, 509, 293, 411, 407, 668, 594, 472, 61, 538, 389, 423, 714, 377, 226, 726, 283, 776, 63, 171, 665, 709, 484, 229, 712, 139, 188, 606, 606, 385, 693, 516, 788, 16, 780, 148, 455, 264, 249, 727, 501, 414, 651, 50, 40, 423, 352, 717, 763, 703, 732, 413, 730, 210, 76, 299, 586, 148, 182, 276, 278, 641, 531, 186, 226, 377, 332, 165, 484, 504, 153, 97, 724, 674, 309, 610, 415, 183, 588, 230, 724, 370, 506, 22, 159, 531, 594, 728, 724, 84, 67, 160, 592, 786, 194, 698, 226, 76, 522, 101, 582, 164, 619, 257, 145, 60, 775, 722, 431, 766, 434, 452, 214, 491, 712, 568, 661, 742, 755, 562, 59, 790, 704, 707, 454, 640, 628, 358, 608, 98, 627, 796, 309, 236, 413, 222, 377, 266, 140, 278, 173, 53, 128, 213, 630, 73, 594, 634, 387, 663, 164, 637, 252, 284, 293, 514, 708, 333, 129, 297, 725, 323, 492, 422, 769, 86, 665, 698, 239, 42, 361, 624, 549, 305, 357, 707, 288, 696, 730, 498, 138, 445, 336, 206, 776, 373, 631, 528, 312, 708, 682, 41, 181, 719, 18, 210, 180, 30, 417, 108, 738, 98, 489, 154, 272, 52, 514, 313, 501, 35, 416, 361, 688, 246, 511, 390, 363, 418, 736, 547, 253, 602, 236, 557, 79, 511, 495, 615, 657, 52, 68, 213, 449, 543, 737, 263, 135, 482, 612, 401, 445, 487, 661, 47, 60, 683, 325, 494, 688, 778, 230, 760, 325, 150, 590, 424, 670, 278, 662, 486, 634, 600, 355, 87, 465, 32, 489, 176, 122, 275, 174, 655, 579, 342, 491, 652, 549, 106, 561, 155, 686, 175, 21, 394, 505, 514, 575, 160, 510, 791, 324, 411, 498, 744, 188, 318, 193, 715, 315, 722, 687, 239, 578, 799, 796, 27, 278, 273, 70, 462, 411, 228, 80, 588, 30, 288, 288, 534, 108, 223, 797, 264, 482, 181, 703, 308, 218, 556, 745, 593, 222, 699, 145, 164, 722, 627, 392, 557, 257, 693, 15, 420, 416, 343, 20, 677, 447, 675, 309, 119, 755, 754, 40, 783, 562, 389, 11, 14, 580, 330, 499, 179, 252, 377, 340, 9, 643, 336, 601, 209, 220, 610, 356, 481, 23, 206, 38, 464, 186, 746, 590, 308, 317, 479, 484, 445, 239, 215, 677, 382, 754, 378, 513, 176, 311, 790, 440, 673, 492, 761, 480, 455, 709, 195, 240, 156, 291, 162, 579, 668, 735, 713, 87, 713, 38, 332, 662, 769, 9, 229, 687, 319, 77, 24, 752, 676, 219, 628, 536, 190, 201, 467, 776, 249, 59, 309, 327, 671, 598, 574, 215, 38, 299, 244, 141, 456, 758, 37, 113, 25, 42, 401, 413, 774, 34, 171, 473, 426, 624, 142, 720, 785, 490, 784, 144, 264, 287, 773, 84, 237, 505, 469, 350, 554, 573, 215, 591, 676, 309, 50, 54, 557, 291, 797, 76, 440, 172, 556, 418, 442, 76, 380, 125, 30, 129, 200, 385, 375, 760, 725, 743, 198, 609, 699, 681, 178, 628, 454, 523, 722, 403, 653, 110, 421, 732, 520, 279, 779, 348, 428, 764, 566, 626, 34, 253, 427, 430, 486, 35, 262, 265, 768, 321, 348, 445, 545, 300, 529, 671, 708, 631, 631, 475, 797, 218, 84, 37, 104, 487, 696, 512, 426, 481, 93, 563, 367, 217, 503, 29, 468, 168, 369, 321, 369, 521, 456, 721, 516, 416, 233, 459, 733, 498, 520, 597, 173, 539, 373, 600, 330, 518, 579, 177, 651, 230, 267, 191, 671, 277, 585, 135, 558, 429, 506, 125, 284, 601, 13, 518, 430, 758, 215, 248, 350, 410, 304, 44, 699, 788, 700, 238, 538, 714, 186, 607, 313, 439, 393, 270, 517, 333, 101, 414, 639, 131, 754, 753, 761, 705, 354, 618, 208, 319, 552, 22, 387, 790, 99, 433, 578, 657, 405, 343, 288, 682, 20, 352, 62, 654, 303, 574, 35, 662, 636, 796, 452, 298, 750, 561, 484, 558, 635, 505, 666, 124, 273, 70, 426, 627, 411, 564, 42, 358, 504, 702, 476, 339, 756, 501, 221, 422, 29, 279, 570, 554, 299, 419, 373, 779, 555, 729, 145, 259, 376, 739, 709, 22, 405, 452, 446, 679, 569, 580, 104, 553, 63, 542, 354, 345, 674, 782, 55, 50, 152, 320, 493, 640, 424, 10, 294, 95, 150, 366, 406, 478, 652, 92, 33, 421, 13, 474, 235, 136, 457, 559, 111, 717, 638, 125, 305, 312, 270, 614, 99, 115, 456, 185, 633, 623, 48, 523, 117, 423, 632, 412, 541, 275, 420, 356, 632, 330, 792, 523, 617, 526, 757, 315, 696, 156, 489, 618, 640, 336, 372, 530, 111, 693, 201, 671, 205, 746, 147, 444, 776, 231, 446, 755, 390, 667, 73, 184, 259, 478, 14, 71, 68, 166, 142, 671, 185, 454, 492, 605, 210, 381, 676, 87, 416, 672, 434, 95, 734, 170, 581, 439, 636, 682, 71, 667, 87, 577, 325, 103, 774, 592, 309, 664, 567, 592, 447, 374, 707, 126, 261, 620, 528, 428, 73, 746, 48, 74, 309, 367, 386, 163, 185, 760, 155, 502, 636, 306};
    uint32_t b[VECT_SIZE] = {163, 214, 424, 553, 355, 142, 476, 128, 318, 331, 753, 338, 322, 321, 737, 267, 253, 72, 91, 671, 790, 607, 420, 692, 658, 143, 783, 776, 16, 784, 269, 366, 321, 639, 706, 22, 232, 743, 470, 518, 291, 665, 409, 771, 724, 330, 177, 529, 439, 297, 456, 29, 443, 390, 338, 647, 390, 93, 799, 724, 247, 233, 614, 284, 691, 254, 412, 529, 800, 91, 307, 15, 706, 107, 597, 127, 400, 479, 78, 742, 760, 656, 199, 539, 776, 79, 485, 223, 185, 217, 263, 368, 626, 714, 330, 556, 716, 378, 280, 657, 541, 40, 77, 36, 688, 719, 335, 626, 50, 228, 793, 480, 302, 657, 532, 311, 703, 31, 409, 66, 602, 486, 11, 505, 608, 189, 13, 517, 401, 521, 750, 416, 622, 213, 95, 719, 540, 393, 491, 237, 169, 616, 482, 36, 460, 107, 586, 770, 535, 190, 509, 293, 411, 407, 668, 594, 472, 61, 538, 389, 423, 714, 377, 226, 726, 283, 776, 63, 171, 665, 709, 484, 229, 712, 139, 188, 606, 606, 385, 693, 516, 788, 16, 780, 148, 455, 264, 249, 727, 501, 414, 651, 50, 40, 423, 352, 717, 763, 703, 732, 413, 730, 210, 76, 299, 586, 148, 182, 276, 278, 641, 531, 186, 226, 377, 332, 165, 484, 504, 153, 97, 724, 674, 309, 610, 415, 183, 588, 230, 724, 370, 506, 22, 159, 531, 594, 728, 724, 84, 67, 160, 592, 786, 194, 698, 226, 76, 522, 101, 582, 164, 619, 257, 145, 60, 775, 722, 431, 766, 434, 452, 214, 491, 712, 568, 661, 742, 755, 562, 59, 790, 704, 707, 454, 640, 628, 358, 608, 98, 627, 796, 309, 236, 413, 222, 377, 266, 140, 278, 173, 53, 128, 213, 630, 73, 594, 634, 387, 663, 164, 637, 252, 284, 293, 514, 708, 333, 129, 297, 725, 323, 492, 422, 769, 86, 665, 698, 239, 42, 361, 624, 549, 305, 357, 707, 288, 696, 730, 498, 138, 445, 336, 206, 776, 373, 631, 528, 312, 708, 682, 41, 181, 719, 18, 210, 180, 30, 417, 108, 738, 98, 489, 154, 272, 52, 514, 313, 501, 35, 416, 361, 688, 246, 511, 390, 363, 418, 736, 547, 253, 602, 236, 557, 79, 511, 495, 615, 657, 52, 68, 213, 449, 543, 737, 263, 135, 482, 612, 401, 445, 487, 661, 47, 60, 683, 325, 494, 688, 778, 230, 760, 325, 150, 590, 424, 670, 278, 662, 486, 634, 600, 355, 87, 465, 32, 489, 176, 122, 275, 174, 655, 579, 342, 491, 652, 549, 106, 561, 155, 686, 175, 21, 394, 505, 514, 575, 160, 510, 791, 324, 411, 498, 744, 188, 318, 193, 715, 315, 722, 687, 239, 578, 799, 796, 27, 278, 273, 70, 462, 411, 228, 80, 588, 30, 288, 288, 534, 108, 223, 797, 264, 482, 181, 703, 308, 218, 556, 745, 593, 222, 699, 145, 164, 722, 627, 392, 557, 257, 693, 15, 420, 416, 343, 20, 677, 447, 675, 309, 119, 755, 754, 40, 783, 562, 389, 11, 14, 580, 330, 499, 179, 252, 377, 340, 9, 643, 336, 601, 209, 220, 610, 356, 481, 23, 206, 38, 464, 186, 746, 590, 308, 317, 479, 484, 445, 239, 215, 677, 382, 754, 378, 513, 176, 311, 790, 440, 673, 492, 761, 480, 455, 709, 195, 240, 156, 291, 162, 579, 668, 735, 713, 87, 713, 38, 332, 662, 769, 9, 229, 687, 319, 77, 24, 752, 676, 219, 628, 536, 190, 201, 467, 776, 249, 59, 309, 327, 671, 598, 574, 215, 38, 299, 244, 141, 456, 758, 37, 113, 25, 42, 401, 413, 774, 34, 171, 473, 426, 624, 142, 720, 785, 490, 784, 144, 264, 287, 773, 84, 237, 505, 469, 350, 554, 573, 215, 591, 676, 309, 50, 54, 557, 291, 797, 76, 440, 172, 556, 418, 442, 76, 380, 125, 30, 129, 200, 385, 375, 760, 725, 743, 198, 609, 699, 681, 178, 628, 454, 523, 722, 403, 653, 110, 421, 732, 520, 279, 779, 348, 428, 764, 566, 626, 34, 253, 427, 430, 486, 35, 262, 265, 768, 321, 348, 445, 545, 300, 529, 671, 708, 631, 631, 475, 797, 218, 84, 37, 104, 487, 696, 512, 426, 481, 93, 563, 367, 217, 503, 29, 468, 168, 369, 321, 369, 521, 456, 721, 516, 416, 233, 459, 733, 498, 520, 597, 173, 539, 373, 600, 330, 518, 579, 177, 651, 230, 267, 191, 671, 277, 585, 135, 558, 429, 506, 125, 284, 601, 13, 518, 430, 758, 215, 248, 350, 410, 304, 44, 699, 788, 700, 238, 538, 714, 186, 607, 313, 439, 393, 270, 517, 333, 101, 414, 639, 131, 754, 753, 761, 705, 354, 618, 208, 319, 552, 22, 387, 790, 99, 433, 578, 657, 405, 343, 288, 682, 20, 352, 62, 654, 303, 574, 35, 662, 636, 796, 452, 298, 750, 561, 484, 558, 635, 505, 666, 124, 273, 70, 426, 627, 411, 564, 42, 358, 504, 702, 476, 339, 756, 501, 221, 422, 29, 279, 570, 554, 299, 419, 373, 779, 555, 729, 145, 259, 376, 739, 709, 22, 405, 452, 446, 679, 569, 580, 104, 553, 63, 542, 354, 345, 674, 782, 55, 50, 152, 320, 493, 640, 424, 10, 294, 95, 150, 366, 406, 478, 652, 92, 33, 421, 13, 474, 235, 136, 457, 559, 111, 717, 638, 125, 305, 312, 270, 614, 99, 115, 456, 185, 633, 623, 48, 523, 117, 423, 632, 412, 541, 275, 420, 356, 632, 330, 792, 523, 617, 526, 757, 315, 696, 156, 489, 618, 640, 336, 372, 530, 111, 693, 201, 671, 205, 746, 147, 444, 776, 231, 446, 755, 390, 667, 73, 184, 259, 478, 14, 71, 68, 166, 142, 671, 185, 454, 492, 605, 210, 381, 676, 87, 416, 672, 434, 95, 734, 170, 581, 439, 636, 682, 71, 667, 87, 577, 325, 103, 774, 592, 309, 664, 567, 592, 447, 374, 707, 126, 261, 620, 528, 428, 73, 746, 48, 74, 309, 367, 386, 163, 185, 760, 155, 502, 636, 306};
    // 1000

	// Naive 
    uint32_t result_naive;
    uint32_t clock, start, end;
    // start count
    clock = 0;
    _mm_mfence();
    start = rdtsc();
    result_naive = mult_naive(a, b, VECT_SIZE);
    // stop count
    end = rdtsc();
    _mm_mfence();
    clock = clock + (end - start);

    printf("%u ticks.\n" , ( end - start));
    printf("The result is: %u.\n", result_naive);

    return 0;
}
