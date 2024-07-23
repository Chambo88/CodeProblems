
var Node = function() {
    this.next = {};
    this.endOfWord = false;
}

var Trie = function() {
    this.first = new Node()
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let current = this.first;
    for (let letter of word)
    {
        if(!(letter in current.next))
        {
            current.next[letter] = new Node();
        }
        current = current.next[letter];
    }
    current.endOfWord = true;
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    let current = this.first;
    for (let letter of word)
    {
        if(!(letter in current.next))
        {
            return false;
        }
        current = current.next[letter]
    }
    return current.endOfWord;
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    let current = this.first;
    for (let letter of prefix)
    {
        if(!(letter in current.next))
        {
            return false;
        }
        current = current.next[letter]
    }
    return true;
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */