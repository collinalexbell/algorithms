object InsertionSort {
  def insertionSort(a: Array[Int]) = {
    var j: Int = 0
    for(i <- 1 until a.length) {
      j = i-1
      val toInsert = a(i)
      while(j>=0 && a(j) > toInsert) {
        a(j+1) = a(j)
        j -= 1
      }
      a(j+1) = toInsert
    }
    a
  }

  def printArr(a: Array[Int]) = {
    for(v <- a){printf("%d, ", v)}
    printf("\n")
  }

  def main(args: Array[String]) = {
    var rv: Array[Int] = Array()
    rv = insertionSort(Array(4,3,5,7,20,44,2,6,44))
    printArr(rv)
  }
}

InsertionSort.main(Array())
