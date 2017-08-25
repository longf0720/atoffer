class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        // 考虑自身给自身赋值
        if (this->m_pData == object.m_pData) {
            return object;
        }
        if (object.m_pData != NULL) {
           int buffer_sz = strlen(object.m_pData);
            if (m_pData == NULL) {
                // malloc first
                m_pData = (char *)malloc(buffer_sz);
                if (m_pData == NULL) {
                    // 异常
                } else {
                    strcpy(m_pData, object.m_pData);
                }
            } else {
                // malloc first, if succ then free
                char *tmp_pData = (char *)malloc(buffer_sz);
                if (m_pData == NULL) {
                    // 异常
                } else {
                    free(m_pData);
                    strcpy(tmp_pData, object.m_pData);
                    m_pData = tmp_pData;
                    tmp_pData = NULL;
                }
            } 
        } else {
            free(m_pData);
            m_pData = NULL;
        }
        
        return *this;
    }
};
