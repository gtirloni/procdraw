(progn
  (ambient-light-color 0 0 (/ 4 5))
  (light-color 0 0 (/ 1 5))
  (setq angle-x (saw))
  (setq angle-y (saw))
  (=> midic-1-1 angle-x 'freq (lambda (x) (lerp (/ -120) (/ 120) x)))
  (=> midic-1-2 angle-y 'freq (lambda (y) (lerp (/ -120) (/ 120) y)))
  (def draw ()
    (background (lerp 0 360 (sigval midic-1-17)) (sigval midic-1-18) 1)
    (color (lerp 0 360 (- 1 (sigval midic-1-17))) (sigval midic-1-18) 1)
    (rotate-x (sigval angle-x))
    (rotate-y (sigval angle-y))
    (scale (lerp (/ 4) 4 (sigval midic-1-19)))
    (cube)))
