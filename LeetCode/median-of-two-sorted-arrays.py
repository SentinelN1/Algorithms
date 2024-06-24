# leetcode.com/problems/median-of-two-sorted-arrays

import numpy as np

# num_max = 1000
# val_min = -1e-6
# val_max = 1e-6

num_max = 10
val_min = -100
val_max = 100

m = np.random.randint(low=0, high=num_max + 1)
n = np.random.randint(low=0, high=num_max + 1)
while n + m == 0:
    m = np.random.randint(low=0, high=num_max + 1)
    n = np.random.randint(low=0, high=num_max + 1)

nums1 = np.sort(np.random.randint(low=val_min, high=val_max + 1, size=m))
nums2 = np.sort(np.random.randint(low=val_min, high=val_max + 1, size=n))


# def findMedianSortedArrays(nums1, nums2):
#     m = len(nums1)
#     n = len(nums2)

#     lb1 = 0
#     rb1 = m - 1
    
#     lb2 = 0
#     rb2 = n - 1

#     lm1 = 0
#     rm1 = 0
#     lm2 = 0
#     rm2 = 0
#     if m % 2 == 0:
#         lm1 = m // 2 - 1
#         rm1 = m // 2
#     else:
#         lm1 = (m - 1) // 2
#         rm1 = (m - 1) // 2


#     if n % 2 == 0:
#         lm2 = n // 2 - 1
#         rm2 = n // 2
#     else:
#         lm2 = (n - 1) // 2
#         rm2 = (n - 1) // 2

#     m1 = nums1[lm1] / 2 + nums1[rm1] / 2
#     m2 = nums2[lm2] / 2 + nums2[rm2] / 2

#     while(rb1 - lb1 > 1 or rb2 - lb2 > 1):
#         if m1 == m2:
#             return m1

#         elif m1 < m2:
#             lb1 = lm1
#             rb2 = rm2

#         elif m1 > m2:
#             rb1 = rm1
#             lb2 = lm2

#         if (rb1 - lb1 + 1) % 2 == 0:
#             lm1 = m // 2 - 1
#             rm1 = m // 2
#         else:
#             lm1 = (m - 1) // 2
#             rm1 = (m - 1) // 2


#         if (rb2 - lb2 + 1) % 2 == 0:
#             lm2 = n // 2 - 1
#             rm2 = n // 2
#         else:
#             lm2 = (n - 1) // 2
#             rm2 = (n - 1) // 2
        
#         m1 = nums1[lm1] / 2 + nums1[rm1] / 2
#         m2 = nums2[lm2] / 2 + nums2[rm2] / 2


#     return m1

# res = findMedianSortedArrays([1, 2], [3, 4])
# print(res)

nums3 = np.sort(np.concatenate([nums1, nums2]))



print(nums1, np.median(nums1))
print(nums2, np.median(nums2))
print(nums3, np.median(nums3))
