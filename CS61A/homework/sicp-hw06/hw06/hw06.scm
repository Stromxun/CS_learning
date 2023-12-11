(define (cddr s)
  (cdr (cdr s)))

(define (cadr s)
  'YOUR-CODE-HERE
  (car (cdr s))
)

(define (caddr s)
  'YOUR-CODE-HERE
  (car (cddr s))
)


(define (sign num)
  'YOUR-CODE-HERE
  (cond ((< num 0) (- 1))
        ((= num 0) (+))
        (else (*))
  )
)


(define (square x) (* x x))

(define (pow x y)
  'YOUR-CODE-HERE
  (cond ((even? y) (pow (square x) (/ y 2)))
  ((= y 1) x)
  (else (* x (pow x (- y 1))))
  )
)

