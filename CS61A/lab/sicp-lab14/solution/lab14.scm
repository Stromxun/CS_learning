(define (split-at lst n)
  (cond
    ((= n 0) (cons nil lst))
    ((null? lst) (cons nil nil))
    (else (let ((p (split-at (cdr lst) (- n 1)))) (cons (cons (car lst) (car p)) (cdr p))))
  )
)


(define (compose-all funcs)
  (if (null? funcs) (lambda (x) x)
    (lambda (x) ((compose-all (cdr funcs)) ((car funcs) x)))
  )
)

