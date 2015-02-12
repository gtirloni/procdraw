(progn
  (ambient-light-color 0 0 (/ 7 10))
  (light-color 0 0 (/ 3 10))
  (color 40 (/ 3 10) (/ 6 10))
  (setq saw-x (saw))
  (setq saw-y (saw))
  (=> mouse-y saw-x 'freq (lambda (y) (lerp (/ 60) (/ -60) y)))
  (=> mouse-x saw-y 'freq (lambda (x) (lerp (/ 60) (/ -60) x)))
  (setq draw (lambda ()
    (progn
      (background 200 (/ 7 10) (/ 9 10))
      (rotate-y (sigval saw-y))
      (rotate-x (sigval saw-x))
      (tetrahedron)))))
