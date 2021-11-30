;; Cannot visulize the algorithm atm...
(defn merge [l r]
  (println l)
  (cond (nil? l) r
        (nil? r) l
        :else (let [[ls & *l] l
                    [rs & *r] r]
                (if (<= ls rs) 
                    (cons ls (merge *l r))
                    (cons rs (merge l *r))))))

(defn sort [list]
  (if (< (count list) 2)
    list
    (let [[l r] (split-at (/ (count list) 2) list)]
      (merge (sort l) (sort r)))))
