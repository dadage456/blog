describe('A suite', function() {
    it('A expectation', function() {
        expect('Hello karma!').toBe('Hello karma!')
    })

    it('A failure', function() {
        expect(true).toBe(false)
    })

    it('A failure again', function() {
        expect(1).toBe(0)
    })
})