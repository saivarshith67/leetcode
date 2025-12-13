from typing import List
import re

class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        # Valid business lines in required order
        order = ["electronics", "grocery", "pharmacy", "restaurant"]
        order_index = {b: i for i, b in enumerate(order)}
        
        # Regex for valid code: alphanumeric + underscore, non-empty
        pattern = re.compile(r'^[A-Za-z0-9_]+$')
        
        valid_coupons = []
        
        for c, b, active in zip(code, businessLine, isActive):
            if (
                active and
                b in order_index and
                c and
                pattern.match(c)
            ):
                valid_coupons.append((order_index[b], c))
        
        # Sort by business line order, then lexicographically by code
        valid_coupons.sort()
        
        # Return only the codes
        return [c for _, c in valid_coupons]

