(ns chapter-1.chapter-1-q7-test
  (:require [clojure.test :refer :all]
            [chapter-1.chapter-1-q7 :refer :all]))

(deftest rotate-matrix-test
  (are [m] (= (nth (iterate rotate-matrix m) 4) m)
           [[1]]
           [[1 2]
            [3 4]]
           [[1 2 3]
            [4 5 6]
            [7 8 9]]
           [[1 2 3 4]
            [5 6 7 8]
            [9 10 11 12]
            [13 14 15 16]]
           [[11 1 34 2 36]
            [44 56 6 78 87]
            [17 88 900 12 42]
            [23 81 564 35 78]
            [2 66 31 9 0]]))

(deftest rotate-matrix-in-place-test
  (are [m] (= (nth (iterate rotate-matrix-in-place m) 4) m)
           [[1]]

           [[1 2]
            [3 4]]

           [[1 2 3]
            [4 5 6]
            [7 8 9]]

           [[1 2 3 4]
            [5 6 7 8]
            [9 10 11 12]
            [13 14 15 16]]

           [[1 2 3 4 5]
            [6 7 8 9 10]
            [11 12 13 14 15]
            [16 17 18 19 20]
            [21 22 23 24 25]]

           [[1 2 3 4 5]
            [6 7 8 9 10]
            [11 12 13 14 15]
            [16 17 18 19 20]
            [21 22 23 24 25]]

           [[ 1  2  3  4  5  6]
            [ 7  8  9 10 11 12]
            [13 14 15 16 17 18]
            [19 20 21 22 23 24]
            [25 26 27 28 29 30]
            [31 32 33 34 35 36]]

           [[11 1 34 2 36]
            [44 56 6 78 87]
            [17 88 900 12 42]
            [23 81 564 35 78]
            [2 66 31 9 0]]))

(deftest rotate-matrix-in-place-test-other
  (is (= (rotate-matrix-in-place [[1]]) [[1]]))
  (is (= (rotate-matrix-in-place [[1 2]
                                  [3 4]]) [[3 1]
                                           [4 2]]))
  (is (= (rotate-matrix-in-place [[1 2 3]
                                  [4 5 6]
                                  [7 8 9]]) [[7 4 1]
                                             [8 5 2]
                                             [9 6 3]]))
  (is (= (rotate-matrix-in-place [[1 2 3 4]
                                  [5 6 7 8]
                                  [9 10 11 12]
                                  [13 14 15 16]]) [[13 9 5 1]
                                                   [14 10 6 2]
                                                   [15 11 7 3]
                                                   [16 12 8 4]]))
  (is (= (rotate-matrix-in-place [[1 2 3 4 5]
                                  [6 7 8 9 10]
                                  [11 12 13 14 15]
                                  [16 17 18 19 20]
                                  [21 22 23 24 25]]) [[21 16 11 6 1]
                                                      [22 17 12 7 2]
                                                      [23 18 13 8 3]
                                                      [24 19 14 9 4]
                                                      [25 20 15 10 5]]))
  (is (= (rotate-matrix-in-place [[ 1  2  3  4  5  6]
                                  [ 7  8  9 10 11 12]
                                  [13 14 15 16 17 18]
                                  [19 20 21 22 23 24]
                                  [25 26 27 28 29 30]
                                  [31 32 33 34 35 36]]) [[31 25 19 13 7 1]
                                                         [32 26 20 14 8 2]
                                                         [33 27 21 15 9 3]
                                                         [34 28 22 16 10 4]
                                                         [35 29 23 17 11 5]
                                                         [36 30 24 18 12 6]])))
